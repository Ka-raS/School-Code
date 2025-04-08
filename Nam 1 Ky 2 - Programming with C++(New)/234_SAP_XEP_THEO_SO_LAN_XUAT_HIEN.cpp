#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

void input(std::unordered_map<int, int> &Map)
{
    int numberOfElements;
    std::cin >> numberOfElements;
    for (int i = 0; i < numberOfElements; ++i)
    {
        int value;
        std::cin >> value;
        ++Map[value];
    }
}

std::vector<std::pair<int, int>> convertVector(const std::unordered_map<int, int> &Map)
{
    std::vector<std::pair<int, int>> Vector;
    for (const std::pair<int, int> &Pair : Map)
        Vector.push_back(Pair);
    return Vector;
}

bool compareFunction(const std::pair<int, int> &pairA, const std::pair<int, int> &pairB)
{
    if (pairA.second == pairB.second)
        return pairA.first < pairB.first;
    return pairA.second > pairB.second;
}

void output(const std::vector<std::pair<int, int>> &Vector)
{
    for (const std::pair<int, int> &Pair : Vector)
        for (int i = 0; i < Pair.second; ++i)
            std::cout << Pair.first << ' ';
    std::cout << std::endl;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        std::unordered_map<int, int> Map;
        input(Map);
        std::vector<std::pair<int, int>> Vector = convertVector(Map);
        std::sort(Vector.begin(), Vector.end(), compareFunction);
        output(Vector);
    }

    return 0;
}