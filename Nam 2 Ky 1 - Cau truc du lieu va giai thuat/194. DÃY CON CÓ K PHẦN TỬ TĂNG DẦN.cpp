#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void input(std::vector<int> &numbers, size_t &subSequenceSize)
{
    size_t arraySize;
    std::cin >> arraySize >> subSequenceSize;
    numbers.resize(arraySize);
    for (int &number : numbers)
        std::cin >> number;
}

void print(const std::vector<int> &numbers)
{
    for (const int number : numbers)
        std::cout << number << ' ';
    std::cout << '\n';
}

void printSubArrays(const std::vector<int> &numbers, const size_t subSequenceSize)
{
    std::vector<int> subSequence;
    subSequence.reserve(subSequenceSize);

    const std::function<void(const size_t)> recursion = [&](const size_t pos) -> void
    {
        if (subSequence.size() == subSequenceSize)
        {
            print(subSequence);
            return;
        }

        for (size_t i = pos; i < numbers.size(); ++i)
        {
            subSequence.emplace_back(numbers[i]);
            recursion(i + 1);
            subSequence.pop_back();
        }
    };

    recursion(0);
}

void runProgram()
{
    size_t subSequenceSize;
    std::vector<int> numbers;
    input(numbers, subSequenceSize);
    std::sort(numbers.begin(), numbers.end());
    printSubArrays(numbers, subSequenceSize);
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}