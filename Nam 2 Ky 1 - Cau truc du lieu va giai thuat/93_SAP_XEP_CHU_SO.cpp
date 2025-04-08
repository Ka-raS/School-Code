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

std::set<int> digitSet(const std::vector<int> &array)
{
    std::set<int> result;

    for (int number : array)
        do
        {
            const int digit = number % 10;
            result.insert(digit);
            number /= 10;
        } while (number != 0);

    return result;
}

void output(const std::set<int> &set)
{
    for (const int number : set)
        std::cout << number << ' ';
    std::cout << '\n';
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    output(digitSet(array));
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}
