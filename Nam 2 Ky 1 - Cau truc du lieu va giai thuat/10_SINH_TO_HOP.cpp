#include <iostream>
#include <vector>

void output(const std::vector<int> &Array)
{
    for (const int element : Array)
        std::cout << element;
    std::cout << ' ';
}

void nextCombination(std::vector<int> &Array, int upperbound, const size_t size)
{
    int i;
    for (i = size - 1; i >= 0; --i)
    {
        if (Array[i] != upperbound)
            break;
        --upperbound;
    }

    if (i >= 0)
    {
        ++Array[i];
        ++i;
    }
    else
        i = 1;
    while (i < size)
    {
        Array[i] = Array[i - 1] + 1;
        ++i;
    }
}

void printCombinations(const int upperbound, const size_t size)
{
    std::vector<int> Array(size);
    for (size_t i = 0; i < size; ++i)
        Array[i] = i + 1;

    const int end = upperbound - size + 1;

    while (true)
    {
        output(Array);
        if (Array[0] == end)
            return;
        nextCombination(Array, upperbound, size);
    }
}

int main()
{
    int testCases;
    std::cin >> testCases;
    for (int test = 0; test < testCases; ++test)
    {
        int upperbound;
        size_t size;
        std::cin >> upperbound >> size;
        printCombinations(upperbound, size);
        std::cout << std::endl;
    }
}