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
        for (std::vector<int> &neighborList : m_adjacencyList) neighborList.reserve(m_vertexCount - 1);

        for (const auto [vertexU, vertexV] : m_edgeList) {
            m_adjacencyList[vertexU].emplace_back(vertexV);
        }

        for (std::vector<int> &neighborList : m_adjacencyList) neighborList.shrink_to_fit();
    }

    void printPath(const int &vertexSource, const int &vertexTarget) const {
        const std::vector<int> path = BreadthFirstSearch(vertexSource, vertexTarget);

        if (path.empty()) {
            std::cout << "-1\n";
            return;
        }

        for (const int &vertex : path) {
            std::cout << vertex << ' ';
        }
        std::cout << '\n';
    }

private:
    std::vector<int> BreadthFirstSearch(const int &vertexSource, const int &vertexTarget) const {
        if (vertexSource == vertexTarget) return std::vector<int>(1, vertexTarget);

        std::vector<bool> visited(m_vertexCount, false);
        visited[vertexSource] = true;

        std::queue<std::pair<int, std::vector<int>>> queue;
        queue.emplace(vertexSource, std::vector<int>(1, vertexSource));

        while (queue.empty() == false) {
            const int vertex = queue.front().first;
            std::vector<int> path = queue.front().second;
            queue.pop();

            const std::vector<int> &neighborList = m_adjacencyList[vertex];
            for (const int neighbor : neighborList) {
                if (visited[neighbor]) {
                    continue;
                }

                visited[neighbor] = true;
                path.emplace_back(neighbor);

                if (neighbor == vertexTarget) {
                    return path;
                }

                queue.emplace(neighbor, path);
                path.pop_back();
            }
        }

        return {};
    }

private:
    int m_vertexCount;
    std::vector<std::pair<int, int>> m_edgeList;
    std::vector<std::vector<int>> m_adjacencyList;
};

void runProgram() {
    int vertexCount, edgeCount, vertexSource, vertexTarget;
    std::cin >> vertexCount >> edgeCount >> vertexSource >> vertexTarget;

    DirectedGraph directedGraph;
    directedGraph.inputEdgeList(vertexCount, edgeCount);
    directedGraph.findAdjacencyList();

    directedGraph.printPath(vertexSource, vertexTarget);
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}