#include <iostream>
#include <vector>
#include <set>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

int missingElement(const std::vector<int> &array)
{
    std::set<int> set(array.begin(), array.end());

    const int min = *set.begin();
    const int max = *set.rbegin();
    const int total = max - min + 1;

    return total - set.size();
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    std::cout << missingElement(array) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}