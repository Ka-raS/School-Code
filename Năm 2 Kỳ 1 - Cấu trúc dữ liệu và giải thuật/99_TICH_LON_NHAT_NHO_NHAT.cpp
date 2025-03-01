#include <iostream>
#include <vector>
#include <algorithm>

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

long long product(const std::vector<int> &array1, const std::vector<int> &array2)
{
    const int max = *std::max_element(array1.begin(), array1.end());
    const int min = *std::min_element(array2.begin(), array2.end());
    return (long long)max * min;
}

void runProgram()
{
    std::vector<int> array1, array2;
    input(array1, array2);
    std::cout << product(array1, array2) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}