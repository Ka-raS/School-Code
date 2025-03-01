#include <iostream>
#include <vector>
#include <functional>

void input(std::vector<int> &numbers, int &sumTarget)
{
    size_t size;
    std::cin >> size >> sumTarget;
    numbers.resize(size);
    for (int &number : numbers)
    {
        std::cin >> number;
    }
}

void print(const std::vector<int> &combination)
{
    std::cout << '[' << combination[0];
    for (size_t i = 1; i < combination.size(); ++i)
    {
        std::cout << ' ' << combination[i];
    }
    std::cout << ']';
}

void printCombinations(const std::vector<int> &numbers, const int sumTarget)
{
    bool printed = false;
    const size_t size = numbers.size();
    std::vector<int> combination;
    combination.reserve(sumTarget);

    const std::function<void(size_t, int)> recursion = [&](size_t pos, int sum) -> void
    {
        if (sum == sumTarget)
        {
            print(combination);
            printed = true;
            return;
        }

        for (size_t i = pos; i < size; ++i)
        {
            if (sum + numbers[i] > sumTarget)
            {
                continue;
            }

            combination.emplace_back(numbers[i]);
            recursion(i, sum + numbers[i]);
            combination.pop_back();
        }
    };

    recursion(0, 0);
    if (!printed)
    {
        std::cout << -1;
    }
    std::cout << '\n';
}

void runProgram()
{
    int sumTarget;
    std::vector<int> numbers;
    input(numbers, sumTarget);
    printCombinations(numbers, sumTarget);
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        runProgram();
    }
}