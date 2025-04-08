#include <iostream>
#include <map>
#include <set>
#include <vector>

class UndirectedGraph {
public:
    class AdjacencyList;
    class EdgeList;
    struct Edge {
        int vertexU;
        int vertexV;
    };

    class EdgeList {
        friend class AdjacencyList;

    public:
        void input() {
            int vertexCount, edgeCount;
            std::cin >> vertexCount >> edgeCount;
            m_list.resize(edgeCount);

            for (Edge &edge : m_list) {
                std::cin >> edge.vertexU >> edge.vertexV;
            }
        }

    private:
        std::vector<Edge> m_list;
    };

    class AdjacencyList {
    public:
        AdjacencyList(const EdgeList &edgeList) {
            for (const Edge &edge : edgeList.m_list) {
                m_list[edge.vertexV].insert(edge.vertexU);
                m_list[edge.vertexU].insert(edge.vertexV);
            }
        }

        void print() const {
            for (const std::pair<int, std::set<int>> &pair : m_list) {
                const int &vertex = pair.first;
                const std::set<int> &neighborList = pair.second;

                std::cout << vertex << ": ";
                for (const int &neighbor : neighborList) {
                    std::cout << neighbor << ' ';
                }
                std::cout << '\n';
            }
        }

    private:
        std::map<int, std::set<int>> m_list;
    };
};

void runProgram() {
    UndirectedGraph::EdgeList edgeList;
    edgeList.input();

    const UndirectedGraph::AdjacencyList adjacencyList(edgeList);
    adjacencyList.print();
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}