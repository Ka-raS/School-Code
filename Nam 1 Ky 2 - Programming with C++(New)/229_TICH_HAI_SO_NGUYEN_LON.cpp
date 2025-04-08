#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string operator*(const std::string &A, const std::string &B)
{
    std::vector<std::string> Products;

    // 45 * 123
    // 3*5=15[5,1]|3*4=12[3,1]=> 135
    // 2*5=10[0,1]|2*4=8[9,0]=> 90 (900)
    // 1*5=5, 1*4 =4 => 45(4500)

    // 5 * 3 = 15 => prod = 5, rem = 1
    // 5 * 2 = 10 => prod = 1, rem = 1
    // 5 * 1 = 5  => prod = 6, rem = 0
    // number = "615"

    // 4 * 3 = 12 => prod = 2, rem = 1
    // 4 * 2 = 8  => prod = 9, rem = 0
    // 4 * 1 = 4  => prod = 4, rem = 0
    // number = "492"
    // res = "4920" + "615" = "5535"
    for (auto it = A.rbegin(); it != A.rend(); ++it)
    {
        std::string number;
        int remainder = 0;

        for (auto jt = B.rbegin(); jt != B.rend(); ++jt)
        {
            int product = (*it - '0') * (*jt - '0') + remainder;
            remainder = product / 10;
            if (product >= 10)
                product = product % 10;
            number.push_back(product + '0');
        }

        if (remainder != 0)
            number.push_back(remainder + '0');
        Products.push_back(number);
    }

    std::string Result(Products.size() + Products.back().size() - 1, '0');

    for (size_t i = 0; i < Products.size(); ++i)
    {
        int remainder = 0;

        for (size_t j = 0; j < Products[i].size(); ++j)
        {
            int number = (Products[i][j] - '0') + (Result[i + j] - '0') + remainder;
            remainder = number / 10;
            if (number >= 10)
                number = number % 10;
            Result[i + j] = number + '0';
        }

        if (remainder != 0)
        {
            if (i + Products[i].size() < Result.size())
                Result[i + Products[i].size()] = '1';
            else
                Result.push_back('1');
        }
    }

    for (size_t i = Result.size() - 1; i > 0; --i)
    {
        if (Result[i] == '0')
            Result.pop_back();
        else
            break;
    }

    std::reverse(Result.begin(), Result.end());
    return Result;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        std::string A, B;
        std::cin >> A >> B;
        std::cout << A * B << std::endl;
    }

    return 0;
}