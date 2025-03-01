#include <iostream>

std::string number(int digitSum, const int digitCount)
{
    std::string answer(digitCount, '0');
    answer[0] = '1';
    --digitSum;

    for (int i = digitCount - 1; i >= 0; --i)
    {
        if (digitSum >= 9)
        {
            answer[i] = '9';
            digitSum -= 9;
        }
        else
        {
            answer[i] = digitSum + '0';
            digitSum = 0;
            break;
        }
    }

    if (digitSum != 0)
        return "-1";
    return answer;
}

void runProgram()
{
    int digitSum, digitCount;
    std::cin >> digitSum >> digitCount;
    std::cout << number(digitSum, digitCount) << '\n';
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