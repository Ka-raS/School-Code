#include <iostream>
#include <vector>

bool next(std::vector<int> &combination, const int number)
{
    if (combination[0] == 1)
        return false;

    size_t i = 0;
    int sum = 0;
    while (i + 1 < combination.size() && combination[i + 1] != 1)
    {
        sum += combination[i];
        ++i;
    }

    --combination[i];
    const int flag = combination[i];
    sum += flag;
    while (sum < number)
    {
        ++i;
        const int value = std::min(flag, number - sum);
        if (i >= combination.size())
        {
            combination.emplace_back(value);
        }
        else
        {
            combination[i] = value;
        }
        sum += flag;
    }
    combination.resize(i + 1);
    return true;
}

void printCombinations(const int number)
{
    std::vector<std::vector<int>> combinations;
    std::vector<int> combination(1, number);
    combinations.reserve(42);
    combinations.reserve(number);
    do
    {
        combinations.emplace_back(combination);
    } while (next(combination, number));

    std::cout << combinations.size() << '\n';
    for (const std::vector<int> &combination : combinations)
    {
        std::cout << '(' << combination[0];
        for (size_t i = 1; i < combination.size(); ++i)
            std::cout << ' ' << combination[i];
        std::cout << ") ";
    }
    std::cout << '\n';
}

void runProgram()
{
    int number;
    std::cin >> number;
    printCombinations(number);
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}