#include <iostream>
#include <sstream>
#include <vector>

class UndirectedGraph {
public:
    void inputAsAdjacencyList() {
        std::cin >> m_vertexCount;
        m_adjacencyList.resize(m_vertexCount);

        for (std::vector<int> &neighborList : m_adjacencyList) {
            neighborList.reserve(m_vertexCount - 1);

            std::string inputLine;
            std::getline(std::cin >> std::ws, inputLine);
            std::istringstream inputStream(inputLine);

            int neighbor;
            while (inputStream >> neighbor) {
                neighborList.emplace_back(neighbor);
            }

            neighborList.shrink_to_fit();
        }
    }

    void findAdjacencyMatrix() {
        m_adjacencyMatrix.resize(m_vertexCount, std::vector<bool>(m_vertexCount, 0));

        for (int vertex = 0; vertex < m_vertexCount; ++vertex) {
            const std::vector<int> &neighborList = m_adjacencyList[vertex];

            for (const int &neighbor : neighborList) {
                m_adjacencyMatrix[vertex][neighbor - 1] = 1;
            }
        }
    }

    void printAdjacencyMatrix() const {
        for (const std::vector<bool> &row : m_adjacencyMatrix) {
            for (const bool square : row) {
                std::cout << square << ' ';
            }
            std::cout << '\n';
        }
    }

private:
    int m_vertexCount;
    std::vector<std::vector<int>> m_adjacencyList;
    std::vector<std::vector<bool>> m_adjacencyMatrix;
};

void runProgram() {
    UndirectedGraph undirectedGraph;
    undirectedGraph.inputAsAdjacencyList();
    undirectedGraph.findAdjacencyMatrix();
    undirectedGraph.printAdjacencyMatrix();
}

int main() {
    runProgram();
}