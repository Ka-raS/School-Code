#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
    int begin;
    int end;
};

void input(std::vector<Node> &nodes)
{
    size_t size;
    std::cin >> size;
    nodes.resize(size);
    for (Node &node : nodes)
        std::cin >> node.begin >> node.end;
}

bool compare(const Node &node1, const Node &node2)
{
    if (node1.end != node2.end)
        return node1.end < node2.end;
    return node1.begin < node2.begin;
}

int max(std::vector<Node> nodes)
{
    std::sort(nodes.begin(), nodes.end(), compare);

    int count = 0;
    int previousEnd = 0;

    for (const Node &node : nodes)
        if (node.begin >= previousEnd)
        {
            ++count;
            previousEnd = node.end;
        }

    return count;
}

void runProgram()
{
    std::vector<Node> nodes;
    input(nodes);
    std::cout << max(nodes) << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}