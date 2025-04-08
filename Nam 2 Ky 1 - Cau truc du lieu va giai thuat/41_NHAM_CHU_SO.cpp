#include <iostream>

void convert(std::string &str, const char from, const char to)
{
    for (char &c : str)
        if (c == from)
            c = to;
}

int minSum(std::string num1, std::string num2)
{
    convert(num1, '6', '5');
    convert(num2, '6', '5');
    return std::stoi(num1) + std::stoi(num2);
}

int maxSum(std::string num1, std::string num2)
{
    convert(num1, '5', '6');
    convert(num2, '5', '6');
    return std::stoi(num1) + std::stoi(num2);
}

int main()
{
    std::string num1, num2;
    std::cin >> num1 >> num2;

    std::cout << minSum(num1, num2) << ' ' << maxSum(num1, num2);
}