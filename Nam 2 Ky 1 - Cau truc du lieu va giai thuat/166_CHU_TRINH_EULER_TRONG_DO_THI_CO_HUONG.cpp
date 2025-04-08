#include <iostream>
#include <vector>

class DirectedConnectedGraph {
public:
    DirectedConnectedGraph(const int vertexCount) {
        m_adjacencyList.resize(vertexCount + 1);
        for (int vertex = 1; vertex <= vertexCount; ++vertex) {
            std::vector<int> &neighborList = m_adjacencyList[vertex];
            neighborList.reserve(vertexCount - 1);
        }
    }

    void addEdge(const int vertexU, const int vertexV) { m_adjacencyList[vertexU].emplace_back(vertexV); }

    void shrink_to_fit() {
        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.shrink_to_fit();
        }
    }

    bool isExistEulerianCircuit() const {
        // check inDegree == outDegree

        const int vertexCount = m_adjacencyList.size() - 1;
        std::vector<int> inDegree(vertexCount + 1, 0);
        std::vector<int> outDegree(vertexCount + 1, 0);

        for (int vertex = 1; vertex <= vertexCount; ++vertex) {
            const std::vector<int> &neighborList = m_adjacencyList[vertex];
            outDegree[vertex] = neighborList.size();

            for (const int neighbor : neighborList) {
                ++inDegree[neighbor];
            }
        }

        return inDegree == outDegree;
    }

private:
    std::vector<std::vector<int>> m_adjacencyList;
};

void runProgram() {
    int vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;

    DirectedConnectedGraph graph(vertexCount);
    for (int edge = 0; edge < edgeCount; ++edge) {
        int vertexU, vertexV;
        std::cin >> vertexU >> vertexV;
        graph.addEdge(vertexU, vertexV);
    }

    graph.shrink_to_fit();
    std::cout << graph.isExistEulerianCircuit() << '\n';
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}