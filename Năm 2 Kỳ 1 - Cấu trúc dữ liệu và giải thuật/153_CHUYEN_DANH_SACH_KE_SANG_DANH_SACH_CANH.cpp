#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

class UndirectedGraph {
public:
    class AdjacencyList;
    class EdgeList {
    public:
        EdgeList(const AdjacencyList &adjacencyList) {
            for (const auto &[vertex, neighborList] : adjacencyList.m_list) {
                for (const int &neighbor : neighborList) {
                    if (vertex < neighbor) {
                        m_list.emplace_back(vertex, neighbor);
                    }
                }
            }
        }

        void print() const {
            for (const std::pair<int, int> &pair : m_list) {
                const int &vertexU = pair.first;
                const int &vertexV = pair.second;
                std::cout << vertexU << ' ' << vertexV << '\n';
            }
        }

    private:
        std::vector<std::pair<int, int>> m_list;
    };

    class AdjacencyList {
        friend class EdgeList;

    public:
        void input() {
            int vertexCount;
            std::cin >> vertexCount;
            std::string inputLine;

            for (int vertex = 1; vertex <= vertexCount; ++vertex) {
                std::getline(std::cin >> std::ws, inputLine);
                std::istringstream inputStream(inputLine);
                int neighbor;
                while (inputStream >> neighbor) {
                    m_list[vertex].emplace(neighbor);
                }
            }
        }

    private:
        std::map<int, std::set<int>> m_list;
    };
};

void runProgram() {
    UndirectedGraph::AdjacencyList adjacencyList;
    adjacencyList.input();

    const UndirectedGraph::EdgeList edgeList(adjacencyList);
    edgeList.print();
}

int main() {
    runProgram();
}