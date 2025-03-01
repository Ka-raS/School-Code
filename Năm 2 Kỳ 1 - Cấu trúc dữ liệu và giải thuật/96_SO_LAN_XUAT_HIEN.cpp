#include <iostream>
#include <vector>
#include <set>

void input(std::vector<int> &array, int &target)
{
    size_t size;
    std::cin >> size >> target;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

int count(const std::vector<int> &array, const int target)
{
    int count = 0;

    size_t i = 0;
    while (i < array.size() && array[i] < target)
        ++i;

    while (i < array.size() && array[i] == target)
    {
        ++count;
        ++i;
    }

    if (count == 0)
        count = -1;
    return count;
}

void runProgram()
{
    int target;
    std::vector<int> array;
    input(array, target);
    std::cout << count(array, target) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}