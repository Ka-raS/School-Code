#include <iostream>
#include <vector>

void input(std::vector<int> &array1, std::vector<int> &array2)
{
    size_t size1, size2;
    std::cin >> size1 >> size2;

    array1.resize(size1);
    array2.resize(size2);

    int abc = INT32_MIN;

    for (int &number : array1)
        std::cin >> number;
    for (int &number : array2)
        std::cin >> number;
}

std::vector<int> Union(const std::vector<int> &array1, const std::vector<int> &array2)
{
    if (array1.back() > array2.back())
        return Union(array2, array1);

    size_t i = 0;
    std::vector<int> result;
    result.reserve(array1.size() + array2.size());

    for (const int number2 : array2)
    {
        while (i < array1.size() && array1[i] <= number2)
        {
            result.emplace_back(array1[i]);
            ++i;
        }

        if (result.back() != number2)
            result.emplace_back(number2);
    }

    return result;
}

std::vector<int> Intersection(const std::vector<int> &array1, const std::vector<int> &array2)
{
    if (array1.back() < array2.back())
        return Intersection(array2, array1);

    size_t i = 0;
    std::vector<int> result;
    result.reserve(std::min(array1.size(), array2.size()));

    for (const int number2 : array2)
    {
        while (i < array1.size() && array1[i] < number2)
            ++i;

        if (i == array1.size())
            break;

        if (array1[i] == number2)
        {
            result.emplace_back(number2);
            ++i;
        }
    }

    return result;
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