#include <iostream>
#include <vector>

class DirectedGraph {
public:
    class EdgeList;

    class AdjacencyList {
    public:
        AdjacencyList(const EdgeList &edgeList) {
            m_list.resize(edgeList.m_vertexCount);
            for (std::vector<int> &neighborList : m_list) {
                neighborList.reserve(edgeList.m_vertexCount);
            }

            for (const auto [vertex, neighbor] : edgeList.m_list) {
                m_list[vertex - 1].emplace_back(neighbor);
            }
        }

        void print() const {
            for (int vertex = 1; vertex <= m_list.size(); ++vertex) {
                std::cout << vertex << ": ";
                for (const int &neighbor : m_list[vertex - 1]) {
                    std::cout << neighbor << ' ';
                }
                std::cout << '\n';
            }
        }

    private:
        std::vector<std::vector<int>> m_list;
    };

    class EdgeList {
        friend AdjacencyList::AdjacencyList(const EdgeList &edgeList);

    public:
        void input() {
            int vertexCount, edgeCount;
            std::cin >> vertexCount >> edgeCount;
            m_vertexCount = vertexCount;
            m_list.resize(edgeCount);

            for (int edge = 0; edge < edgeCount; ++edge) {
                auto &[vertexU, vertexV] = m_list[edge];
                std::cin >> vertexU >> vertexV;
            }
        }

    private:
        int m_vertexCount;
        std::vector<std::pair<int, int>> m_list;
    };
};

void runProgram() {
    DirectedGraph::EdgeList edgeList;
    edgeList.input();

    const DirectedGraph::AdjacencyList adjacency(edgeList);
    adjacency.print();
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}