#include <iostream>
#include <stack>
#include <vector>

class UndirectedConnectedGraph {
public:
    UndirectedConnectedGraph(const int vertexCount) {
        m_adjacencyList.resize(vertexCount + 1);
        for (int vertex = 1; vertex <= vertexCount; ++vertex) {
            std::vector<int> &neighborList = m_adjacencyList[vertex];
            neighborList.reserve(vertexCount - 1);
        }
    }

    void addEdge(const int vertexU, const int vertexV) {
        m_adjacencyList[vertexU].emplace_back(vertexV);
        m_adjacencyList[vertexV].emplace_back(vertexU);
    }

    void shrink_to_fit() {
        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.shrink_to_fit();
        }
    }

    // return 2 if graph has Eulerian Circuit
    // return 1 if graph has Eulerian Trail
    // return 0 if graph has neither
    int isExistEulerianCircuitOrTrail() const {
        int oddDegreeCount = 0;
        const int vertexCount = m_adjacencyList.size() - 1;

        for (int vertex = 1; vertex <= vertexCount; ++vertex) {
            const std::vector<int> &neighborList = m_adjacencyList[vertex];
            if (neighborList.size() % 2 != 0) {
                ++oddDegreeCount;
            }
        }

        if (oddDegreeCount == 0) {
            return 2;
        }
        if (oddDegreeCount == 2) {
            return 1;
        }
        return 0;
    }

private:
    std::vector<std::vector<int>> m_adjacencyList;
};

void runProgram() {
    int vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;

    UndirectedConnectedGraph graph(vertexCount);
    for (int edge = 0; edge < edgeCount; ++edge) {
        int vertexU, vertexV;
        std::cin >> vertexU >> vertexV;
        graph.addEdge(vertexU, vertexV);
    }

    graph.shrink_to_fit();
    std::cout << graph.isExistEulerianCircuitOrTrail() << '\n';
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}