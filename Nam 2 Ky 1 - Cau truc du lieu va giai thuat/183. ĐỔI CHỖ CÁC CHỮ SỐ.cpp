#include <iostream>
#include <functional>

std::string maxNumber(std::string &number, int swapCount)
{
    std::string answer;

    const std::function<void(const size_t)> recursion = [&](const size_t pos) -> void
    {
        if (answer < number)
        {
            answer = number;
        }
        if (swapCount <= 0)
        {
            return;
        }

        for (size_t i = 0; i < number.size(); ++i)
        {
            for (size_t j = pos; j < number.size(); ++j)
            {
                --swapCount;
                std::swap(number[i], number[j]);
                recursion(j + 1);
                std::swap(number[i], number[j]);
                ++swapCount;
            }
        }
    };

    recursion(0);
    return answer;
}

void runProgram()
{
    int swapCount;
    std::string number;
    std::cin >> swapCount >> number;
    std::cout << maxNumber(number, swapCount) << '\n';
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