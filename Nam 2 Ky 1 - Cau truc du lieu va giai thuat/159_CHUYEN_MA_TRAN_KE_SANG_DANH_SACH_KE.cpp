#include <iostream>
#include <sstream>
#include <vector>

class UndirectedGraph {
public:
    void inputAsAdjacencyMatrix() {
        std::cin >> m_vertexCount;
        m_adjacencyMatrix.resize(m_vertexCount, std::vector<bool>(m_vertexCount));

        for (std::vector<bool> &row : m_adjacencyMatrix)
            for (size_t i = 0, n = row.size(); i < n; ++i) {
                bool inputValue;
                std::cin >> inputValue;
                row[i] = inputValue;
            }
    }

    void findAdjacencyList() {
        m_adjacencyList.resize(m_vertexCount);

        for (size_t vertex = 0; vertex < m_vertexCount; ++vertex) {
            m_adjacencyList[vertex].reserve(m_vertexCount - 1);

            for (size_t neighbor = 0; neighbor < m_vertexCount; ++neighbor) {
                if (m_adjacencyMatrix[vertex][neighbor] == true) {
                    m_adjacencyList[vertex].emplace_back(neighbor + 1);
                }
            }

            m_adjacencyList[vertex].shrink_to_fit();
        }
    }

    void printAdjacencyList() const {
        for (const std::vector<int> &neighborList : m_adjacencyList) {
            for (const int &neighbor : neighborList) {
                std::cout << neighbor << ' ';
            }
            std::cout << '\n';
        }
    }

private:
    int m_vertexCount;
    std::vector<std::vector<bool>> m_adjacencyMatrix;
    std::vector<std::vector<int>> m_adjacencyList;
};

void runProgram() {
    UndirectedGraph undirectedGraph;
    undirectedGraph.inputAsAdjacencyMatrix();
    undirectedGraph.findAdjacencyList();
    undirectedGraph.printAdjacencyList();
}

int main() {
    runProgram();
}