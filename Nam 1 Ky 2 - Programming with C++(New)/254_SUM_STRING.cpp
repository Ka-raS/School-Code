#include <iostream>
#include <algorithm>

std::string addition(const std::string &A, const std::string &B)
{
    std::string result;
    int carry = 0;
    int i = A.length() - 1;
    int j = B.length() - 1;
    while (i >= 0 || j >= 0 || carry != 0)
    {
        const int digitA = (i >= 0) ? A[i] - '0' : 0;
        const int digitB = (j >= 0) ? B[j] - '0' : 0;
        const int sum = digitA + digitB + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
        --i, --j;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

bool isEqual(std::string firstPart, std::string secondPart, const std::string &str)
{
    size_t startingPos = firstPart.length() + secondPart.length();
    const size_t strLen = str.length();
    while (startingPos < strLen)
    {
        const std::string sumFirstAndSecond = addition(firstPart, secondPart);
        const std::string sumThirdAndFourth = str.substr(startingPos, sumFirstAndSecond.length());
        if (sumFirstAndSecond == sumThirdAndFourth)
        {
            firstPart = secondPart;
            secondPart = sumFirstAndSecond;
            startingPos += sumFirstAndSecond.length();
        }
        else
            return false;
    }
    return true;
}

bool isSumString(const std::string &str)
{
    std::string firstPart;
    const size_t i_end = str.length() / 2;
    const size_t j_end = str.length() * 2 / 3;
    for (size_t i = 0; i <= i_end; ++i)
    {
        firstPart.push_back(str[i]);
        std::string secondPart;
        for (size_t j = i + 1; j <= j_end; ++j)
        {
            secondPart.push_back(str[j]);
            if (isEqual(firstPart, secondPart, str))
                return true;
        }
    }
    return false;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::string str;
        std::cin >> str;
        if (isSumString(str))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
}