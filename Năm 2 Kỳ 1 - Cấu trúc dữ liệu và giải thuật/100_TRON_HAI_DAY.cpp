#include <iostream>
#include <vector>
#include <set>

void input(std::vector<int> &array1, std::vector<int> &array2)
{
    size_t size1, size2;
    std::cin >> size1 >> size2;

    array1.resize(size1);
    array2.resize(size2);

    for (int &number : array1)
        std::cin >> number;
    for (int &number : array2)
        std::cin >> number;
}

std::multiset<int> merge(const std::vector<int> &array1, const std::vector<int> &array2)
{
    std::multiset<int> result;
    result.insert(array1.begin(), array1.end());
    result.insert(array2.begin(), array2.end());
    return result;
}

void output(const std::multiset<int> &set)
{
    for (const int number : set)
        std::cout << number << ' ';
    std::cout << '\n';
}

void runProgram()
{
    std::vector<int> array1, array2;
    input(array1, array2);
    output(merge(array1, array2));
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}