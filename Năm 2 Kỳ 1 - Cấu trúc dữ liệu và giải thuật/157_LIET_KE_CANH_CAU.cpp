#include <iostream>
#include <queue>
#include <set>
#include <vector>

class UndirectedGraph {
public:
    void inputAsEdgeList() {
        std::cin >> m_vertexCount >> m_edgeCount;
        m_edgeList.resize(m_edgeCount);

        for (auto &[vertexU, vertexV] : m_edgeList) {
            std::cin >> vertexU >> vertexV;
        }
    }

    void findAdjacencyList() {
        m_adjacencyList.resize(m_vertexCount + 1);
        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.reserve(m_vertexCount);
        }

        for (const auto [vertexU, vertexV] : m_edgeList) {
            m_adjacencyList[vertexU].emplace_back(vertexV);
            m_adjacencyList[vertexV].emplace_back(vertexU);
        }

        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.shrink_to_fit();
        }
    }

    void findBridgeList() {
        m_bridgeList.reserve(m_vertexCount);

        for (int vertex = 1; vertex < m_adjacencyList.size(); ++vertex) {
            const std::vector<int> &neighborList = m_adjacencyList[vertex];
            for (const int neighbor : neighborList) {
                if (vertex < neighbor && isBridge(vertex, neighbor)) {
                    m_bridgeList.emplace_back(vertex, neighbor);
                }
            }
        }

        m_bridgeList.shrink_to_fit();
    }

    void printBridgeList() const {
        for (const auto [vertexU, vertexV] : m_bridgeList) {
            std::cout << vertexU << ' ' << vertexV << ' ';
        }

        std::cout << '\n';
    }

private:
    bool isBridge(const int vertexSource, const int vertexTarget) const {
        // Breadth-First Search
        std::queue<int> queue;
        std::vector<bool> visited(m_vertexCount + 1, false);

        visited[vertexSource] = true;
        for (const int neighbor : m_adjacencyList[vertexSource]) {
            if (neighbor != vertexTarget) {
                queue.emplace(neighbor);
            }
        }

        while (queue.empty() == false) {
            const int vertex = queue.front();
            queue.pop();

            if (vertex == vertexTarget) {
                return false;
            }
            visited[vertex] = true;

            for (const int &neighbor : m_adjacencyList[vertex]) {
                if (visited[neighbor] == false) {
                    queue.emplace(neighbor);
                }
            }
        }

        return true;
    }

private:
    int m_vertexCount;
    int m_edgeCount;
    std::vector<std::vector<int>> m_adjacencyList;
    std::vector<std::pair<int, int>> m_edgeList;
    std::vector<std::pair<int, int>> m_bridgeList;
};

void runProgram() {
    UndirectedGraph undirectedGraph;
    undirectedGraph.inputAsEdgeList();
    undirectedGraph.findAdjacencyList();
    undirectedGraph.findBridgeList();
    undirectedGraph.printBridgeList();
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}