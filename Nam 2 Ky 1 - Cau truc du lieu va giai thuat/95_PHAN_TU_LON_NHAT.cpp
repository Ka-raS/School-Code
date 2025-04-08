#include <iostream>
#include <vector>
#include <set>

void input(std::vector<int> &array, size_t &maxElementsSize)
{
    size_t size;
    std::cin >> size >> maxElementsSize;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

void output(const std::vector<int> &array, const size_t maxElementsSize)
{
    const std::multiset<int> set(array.begin(), array.end());

    auto it = set.rbegin();
    for (int i = 0; i < maxElementsSize; ++i, ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

void runProgram()
{
    size_t maxElementsSize;
    std::vector<int> array;
    input(array, maxElementsSize);
    output(array, maxElementsSize);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}
