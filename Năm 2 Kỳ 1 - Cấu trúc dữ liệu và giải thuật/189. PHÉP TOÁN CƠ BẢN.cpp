#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> findAllNums(const std::string &num)
{
    std::vector<int> list;

    if (num == "??")
    {
        list.resize(90);
        std::iota(list.begin(), list.end(), 10);
    }
    else if (num[0] == '?')
    {
        list.resize(9);
        for (size_t i = 0; i < 9; ++i)
            list[i] = (num[1] - '0') + 10 * (i + 1);
    }
    else if (num[1] == '?')
    {
        list.resize(10);
        for (size_t i = 0; i < 10; ++i)
            list[i] = (num[0] - '0') * 10 + i;
    }
    else
    {
        list.emplace_back(std::stoi(num));
    }

    return list;
}

std::string predict(const std::string &expression)
{
    const std::vector<int> left = findAllNums(expression.substr(0, 2)),
                           right = findAllNums(expression.substr(5, 2)),
                           answer = findAllNums(expression.substr(10, 2));

    const bool isAdd = (expression[3] == '?') || (expression[3] == '+');
    const bool isSub = (expression[3] == '?') || (expression[3] == '-');
    const bool isMul = (expression[3] == '?') || (expression[3] == '*');
    const bool isDiv = (expression[3] == '?') || (expression[3] == '/');

    const auto find = [&answer](const int value) -> bool
    {
        return std::binary_search(answer.begin(), answer.end(), value);
    };
    const auto convert = [](const int l, const char o, const int r, const int a) -> std::string
    {
        return std::to_string(l) + ' ' + o + ' ' + std::to_string(r) + " = " + std::to_string(a);
    };

    std::string returnExpression = "WRONG PROBLEM!";
    for (const int r : right)
    {
        for (const int l : left)
        {
            if (isAdd && find(l + r))
            {
                std::string expr = convert(l, '+', r, l + r);
                if (returnExpression > expr)
                    returnExpression = std::move(expr);
            }
            if (isSub && find(l - r))
            {
                std::string expr = convert(l, '-', r, l - r);
                if (returnExpression > expr)
                    returnExpression = std::move(expr);
            }
            if (isMul && find(l * r))
            {
                std::string expr = convert(l, '*', r, l * r);
                if (returnExpression > expr)
                    returnExpression = std::move(expr);
            }
            if (isDiv && find(l / r))
            {
                std::string expr = convert(l, '/', r, l / r);
                if (returnExpression > expr)
                    returnExpression = std::move(expr);
            }
        }
    }

    return returnExpression;
}

void runProgram()
{
    std::string unclearExpression;
    std::getline(std::cin >> std::ws, unclearExpression);
    std::cout << predict(unclearExpression) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}