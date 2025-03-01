#include <iostream>
#include <queue>
#include <vector>

class DirectedGraph {
public:
    void inputEdgeList(const int &vertexCount, const int &edgeCount) {
        m_vertexCount = vertexCount;
        m_edgeList.resize(edgeCount);

        for (auto &[vertexU, vertexV] : m_edgeList) {
            std::cin >> vertexU >> vertexV;
        }
    }

    void findAdjacencyList() {
        m_adjacencyList.resize(m_vertexCount + 1);
        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.reserve(m_vertexCount - 1);
        }

        for (const auto [vertexU, vertexV] : m_edgeList) {
            m_adjacencyList[vertexU].emplace_back(vertexV);
        }

        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.shrink_to_fit();
        }
    }

    void printStartingFrom(const int &vertexSource) const {
        // Breadth-First Search

        std::vector<bool> visited(m_vertexCount + 1, false);
        std::queue<int> queue;
        queue.emplace(vertexSource);
        visited[vertexSource] = true;

        while (queue.empty() == false) {
            const int vertex = queue.front();
            queue.pop();
            std::cout << vertex << ' ';

            const std::vector<int> &neighborList = m_adjacencyList[vertex];
            for (const int &neighbor : neighborList) {
                if (visited[neighbor] == false) {
                    queue.emplace(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        std::cout << '\n';
    }

private:
    int m_vertexCount;
    std::vector<std::pair<int, int>> m_edgeList;
    std::vector<std::vector<int>> m_adjacencyList;
};

void runProgram() {
    int vertexCount, edgeCount, vertexSource;
    std::cin >> vertexCount >> edgeCount >> vertexSource;

    DirectedGraph directedGraph;
    directedGraph.inputEdgeList(vertexCount, edgeCount);
    directedGraph.findAdjacencyList();

    directedGraph.printStartingFrom(vertexSource);
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}