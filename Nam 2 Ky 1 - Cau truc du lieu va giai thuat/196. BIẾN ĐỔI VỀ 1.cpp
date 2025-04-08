#include <iostream>
#include <queue>
#include <vector>

int minConversions(const int number)
{
    std::vector<int> stepsTotal(number + 1, INT32_MAX);
    std::queue<std::pair<int, int>> path;
    path.emplace(number, 0);
    while (!path.empty())
    {
        const auto [num, steps] = path.front();
        path.pop();

        if (stepsTotal[num] < steps)
            continue;
        stepsTotal[num] = steps;
        if (num == 1)
            break;

        if (num % 3 == 0)
            path.emplace(num / 3, steps + 1);
        if (num % 2 == 0)
            path.emplace(num / 2, steps + 1);
        path.emplace(num - 1, steps + 1);
    }
    return stepsTotal[1];
}

void runProgram()
{
    int number;
    std::cin >> number;
    std::cout << minConversions(number) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}