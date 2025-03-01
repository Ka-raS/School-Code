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

std::vector<int> Union(const std::vector<int> &array1, const std::vector<int> &array2)
{
    std::set<int> result;
    result.insert(array1.begin(), array1.end());
    result.insert(array2.begin(), array2.end());
    return std::vector<int>(result.begin(), result.end());
}

std::vector<int> Intersection(const std::vector<int> &array1, const std::vector<int> &array2)
{
    std::set<int> result;

    std::set<int> set1(array1.begin(), array1.end());
    for (const int number : array2)
        if (set1.count(number))
            result.insert(number);

    return std::vector<int>(result.begin(), result.end());
}

void output(const std::vector<int> &array)
{
    for (const int number : array)
        std::cout << number << ' ';
    std::cout << '\n';
}

void runProgram()
{
    std::vector<int> array1, array2;
    input(array1, array2);
    output(Union(array1, array2));
    output(Intersection(array1, array2));
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}