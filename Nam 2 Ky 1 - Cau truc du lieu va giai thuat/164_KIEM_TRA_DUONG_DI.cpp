#include <iostream>
#include <stack>
#include <vector>

class UndirectedGraph {
public:
    void inputAsEdgeList() {
        std::cin >> m_vertexCount >> m_edgeCount;
        m_edgeList.resize(m_edgeCount);

        for (auto &[vertexU, vertexV] : m_edgeList) {
            std::cin >> vertexU >> vertexV;
        }

        findAdjacencyList();
    }

    bool isExistPath(const int vertexSource, const int vertexDestination) const {
        // Depth-First Search
        std::stack<int> stack;
        stack.emplace(vertexSource);

        std::vector<bool> visited(m_vertexCount + 1, false);

        while (stack.empty() == false) {
            const int vertex = stack.top();
            stack.pop();
            visited[vertex] = true;

            if (vertex == vertexDestination) {
                return true;
            }

            const std::vector<int> &neighborList = m_adjacencyList[vertex];

            for (const int neighbor : neighborList) {
                if (visited[neighbor] == false) {
                    stack.emplace(vertex);
                    stack.emplace(neighbor);
                    break;
                }
            }
        }

        return false;
    }

private:
    void findAdjacencyList() {
        m_adjacencyList.resize(m_vertexCount + 1);
        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.reserve(m_vertexCount - 1);
        }

        for (const auto [vertexU, vertexV] : m_edgeList) {
            m_adjacencyList[vertexU].emplace_back(vertexV);
            m_adjacencyList[vertexV].emplace_back(vertexU);
        }

        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.shrink_to_fit();
        }
    }

private:
    int m_vertexCount;
    int m_edgeCount;
    std::vector<std::pair<int, int>> m_edgeList;
    std::vector<std::vector<int>> m_adjacencyList;
};

void runProgram() {
    UndirectedGraph undirectedGraph;
    undirectedGraph.inputAsEdgeList();

    int questionCount;
    std::cin >> questionCount;
    for (int question = 0; question < questionCount; ++question) {
        int vertexSource, vertexDestination;
        std::cin >> vertexSource >> vertexDestination;

        if (undirectedGraph.isExistPath(vertexSource, vertexDestination)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}