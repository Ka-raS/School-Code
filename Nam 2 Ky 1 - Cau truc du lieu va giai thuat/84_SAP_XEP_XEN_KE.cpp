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

void alternatingSort(std::vector<int> &array)
{
    const size_t size = array.size();
    for (size_t i = 0; i < size - 1; ++i)
    {
        const bool iIsEven = i % 2 == 0;
        size_t pos = i;

        for (size_t j = i + 1; j < size; ++j)
            if (iIsEven && array[j] > array[pos] || !iIsEven & array[j] < array[pos])
                pos = j;

        if (pos != i)
            std::swap(array[i], array[pos]);
    }
}

void output(const std::vector<int> &array)
{
    for (const int number : array)
        std::cout << number << ' ';
    std::cout << '\n';
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    alternatingSort(array);
    output(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}