#include <iostream>
#include <vector>
#include <functional>

void input(std::vector<int> &numbers, int &sumTarget)
{
    size_t size;
    std::cin >> size >> sumTarget;
    numbers.resize(size);
    for (int &number : numbers)
        std::cin >> number;
}

void output(const std::vector<std::vector<int>> &answers)
{
    std::cout << (int)answers.size() - answers.empty();
    for (const std::vector<int> &answer : answers)
    {
        std::cout << " {" << answer[0];
        for (size_t i = 1; i < answer.size(); ++i)
            std::cout << ' ' << answer[i];
        std::cout << '}';
    }
    std::cout << '\n';
}

std::vector<std::vector<int>> combinations(const std::vector<int> &numbers, const int sumTarget)
{
    std::vector<std::vector<int>> answers;
    std::vector<int> answer;
    answer.reserve(sumTarget);

    const std::function<void(const size_t, const int)> recursion = [&](const size_t pos, const int sum) -> void
    {
        if (sum == sumTarget)
        {
            answers.emplace_back(answer);
            return;
        }
        if (sum > sumTarget)
        {
            return;
        }

        for (size_t i = pos; i < numbers.size(); ++i)
        {
            answer.emplace_back(numbers[i]);
            recursion(i, sum + numbers[i]);
            answer.pop_back();
        }
    };

    recursion(0, 0);
    return answers;
}

void runProgram()
{
    int sumTarget;
    std::vector<int> numbers;
    input(numbers, sumTarget);
    output(combinations(numbers, sumTarget));
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}