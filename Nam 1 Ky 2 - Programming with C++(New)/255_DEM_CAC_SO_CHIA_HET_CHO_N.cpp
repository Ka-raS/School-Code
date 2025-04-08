#include <iostream>
#include <vector>
#include <algorithm>

std::string addition(const std::string &, const std::string &);
std::string countDividend(const std::string &num, const int divisor)
{
    std::vector<std::string> count(divisor);
    for (const char c : num)
    {
        const int digit = (c - '0') % divisor;
        std::vector<std::string> tmp(divisor);
        tmp[digit] = "1";
        for (int d = 0; d < divisor; ++d)
        {
            tmp[d] = addition(tmp[d], count[d]);
            const int n = (d * 10 + digit) % divisor;
            tmp[n] = addition(tmp[n], count[d]);
        }
        count = tmp;
    }
    return count[0];
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::string num;
        size_t numLenth;
        int divisor;
        std::cin >> numLenth >> divisor >> num;
        std::cout << countDividend(num, divisor) << std::endl;
    }
    return 0;
}

std::string addition(const std::string &A, const std::string &B)
{
    if (A.empty() && B.empty())
        return "0";
    std::string res;
    int carry = 0;
    int i = A.length() - 1;
    int j = B.length() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        const int digitA = (i >= 0) ? A[i] - '0' : 0;
        const int digitB = (j >= 0) ? B[j] - '0' : 0;
        const int sum = digitA + digitB + carry;
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
        --i, --j;
    }
    std::reverse(res.begin(), res.end());
    return res;
}