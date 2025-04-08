#include <iostream>
#include <vector>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

void printPositionsSubArrayNeedSorted(const std::vector<int> &array)
{
    size_t left = 0;
    size_t right = array.size() - 1;

    while (left < right && array[left] <= array[left + 1])
        ++left;

    while (left < right && array[right - 1] <= array[right])
        --right;

    int min = array[left];
    int max = array[left];

    for (size_t i = left + 1; i <= right; ++i)
    {
        if (min > array[i])
            min = array[i];
        else if (max < array[i])
            max = array[i];
    }

    while (left > 0 && array[left - 1] > min)
        --left;

    while (right < array.size() - 1 && array[right + 1] < max)
        ++right;

    std::cout << left + 1 << ' ' << right + 1 << '\n';
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    printPositionsSubArrayNeedSorted(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}