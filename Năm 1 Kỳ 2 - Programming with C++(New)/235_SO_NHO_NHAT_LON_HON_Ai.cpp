#include <iostream>
#include <vector>
#include <map>

std::vector<int> input()
{
    int numberOfElements;
    std::cin >> numberOfElements;
    std::vector<int> Array(numberOfElements);
    for (int &element : Array)
        std::cin >> element;
    return Array;
}

std::map<int, bool> convertMap(const std::vector<int> &Array)
{
    std::map<int, bool> Map;
    for (const int &element : Array)
        Map[element] = true;
    return Map;
}

void output(const std::vector<int> &Array, const std::map<int, bool> &Map)
{
    for (const int &element : Array)
    {
        const auto up = Map.upper_bound(element);
        if (up != Map.end())
            std::cout << up->first << ' ';
        else
            std::cout << '_' << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        const std::vector<int> Array = input();
        const std::map<int, bool> Map = convertMap(Array);
        output(Array, Map);
    }

    return 0;
}