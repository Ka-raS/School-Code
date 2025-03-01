#include <iostream>
#include <queue>
#include <set>
#include <vector>

class UndirectedGraph {
public:
    class EdgeList;

    class AdjacencyList {
    public:
        AdjacencyList(const EdgeList &edgeList) {
            m_vertexCount = edgeList.m_vertexCount;
            m_list.resize(m_vertexCount);

            for (const auto [vertex, neighbor] : edgeList.m_list) {
                m_list[vertex - 1].emplace(neighbor);
                m_list[neighbor - 1].emplace(vertex);
            }
        }

        void printMinimumSpanningTree(const int &vertexBegin) const {
            std::vector<bool> visited(m_vertexCount, false);
            std::queue<int> queue;
            queue.emplace(vertexBegin);
            visited[vertexBegin - 1] = true;

            while (queue.empty() == false) {
                const int vertex = queue.front();
                queue.pop();
                std::cout << vertex << ' ';

                for (const int neighbor : m_list[vertex - 1])
                    if (visited[neighbor - 1] == false) {
                        queue.emplace(neighbor);
                        visited[neighbor - 1] = true;
                    }
            }

            std::cout << '\n';
        }

    private:
        int m_vertexCount;
        std::vector<std::set<int>> m_list;
    };

    class EdgeList {
        friend AdjacencyList::AdjacencyList(const EdgeList &edgeList);

    public:
        EdgeList(const int &vertexCount, const int &edgeCount) : m_vertexCount(vertexCount) {
            m_list.resize(edgeCount);
        }

        void input() {
            for (auto &[vertexU, vertexV] : m_list) {
                std::cin >> vertexU >> vertexV;
            }
        }

    private:
        int m_vertexCount;
        std::vector<std::pair<int, int>> m_list;
    };
};

void runProgram() {
    int vertexCount, edgeCount, vertexBegin;
    std::cin >> vertexCount >> edgeCount >> vertexBegin;

    UndirectedGraph::EdgeList edgeList(vertexCount, edgeCount);
    edgeList.input();

    const UndirectedGraph::AdjacencyList adjacency(edgeList);
    adjacency.printMinimumSpanningTree(vertexBegin);
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        runProgram();
    }
}