#include <iostream>
#include <vector>

void convertNextArray(std::vector<int> &Array, int upperbound)
{
    int i;
    for (i = Array.size() - 1; i >= 0; --i)
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
    {
        Array[0] = 1;
        i = 1;
    }
    while (i < Array.size())
    {
        Array[i] = Array[i - 1] + 1;
        ++i;
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
        std::vector<int> Array(size);
        for (int &element : Array)
            std::cin >> element;

        convertNextArray(Array, upperbound);
        for (const int element : Array)
            std::cout << element << ' ';
        std::cout << std::endl;
    }
}