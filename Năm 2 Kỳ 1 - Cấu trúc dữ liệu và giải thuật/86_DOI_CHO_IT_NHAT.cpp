#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

int selectionSortSwaps(std::vector<int> array)
{
    int swaps = 0;
    const size_t size = array.size();

    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t min = i;

        for (size_t j = i + 1; j < size; ++j)
            if (array[j] < array[min])
                min = j;

        if (min != i)
        {
            std::swap(array[i], array[min]);
            ++swaps;
        }
    }

    return swaps;
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    std::cout << selectionSortSwaps(array) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}