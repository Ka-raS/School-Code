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

void outputMinFirstAndSecond(const std::vector<int> &array)
{
    int minFirst = INT32_MAX;
    for (const int number : array)
        if (minFirst > number)
            minFirst = number;

    int minSecond = INT32_MAX;
    for (const int number : array)
        if (minSecond > number && number > minFirst)
            minSecond = number;

    if (minSecond == INT32_MAX)
    {
        std::cout << "-1\n";
        return;
    }

    std::cout << minFirst << ' ' << minSecond << '\n';
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    outputMinFirstAndSecond(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}