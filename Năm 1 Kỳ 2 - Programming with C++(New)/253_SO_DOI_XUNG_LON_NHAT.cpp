#include <iostream>
#include <algorithm>

// void printRightLargestPalindromicNumber(const std::string &number);

bool everyDigitCountIsOdd(const int *digitCounts)
{
    int counts = 0;
    int oddCounts = 0;
    for (int digit = 1; digit <= 9; ++digit)
        if (digitCounts[digit] != 0)
        {
            ++counts;
            if (digitCounts[digit] % 2 == 1)
                ++oddCounts;
        }
    return counts == oddCounts;
}

std::string maxCountDigitStr(const int *digitCounts)
{
    int maxDigit = -1;
    int maxCount = -1;
    for (int digit = 9; digit >= 1; --digit)
        if (maxCount < digitCounts[digit])
        {
            maxCount = digitCounts[digit];
            maxDigit = digit;
        }
    return std::string(maxCount, maxDigit + '0');
}

std::string findLeftPart(const int *digitCounts)
{
    std::string result;
    for (int digit = 9; digit >= 0; --digit)
        if (digitCounts[digit] % 2 == 0)
            result += std::string(digitCounts[digit] / 2, digit + '0');
    if (result[0] == '0')
        return "";
    return result;
}

std::string findRightPart(std::string leftPart)
{
    std::reverse(leftPart.begin(), leftPart.end());
    return leftPart;
}

std::string findMiddlePart(const int *digitCounts)
{
    int maxDigit = -1;
    int maxCount = 0;
    for (int digit = 9; digit >= 0; --digit)
        if (digitCounts[digit] % 2 == 1 && digitCounts[digit] > maxCount)
        {
            maxCount = digitCounts[digit];
            maxDigit = digit;
        }
    if (maxCount == 0)
        return "";
    return std::string(maxCount, maxDigit + '0');
}

std::string wrongLargestPalindromicNumber(const std::string &number)
{
    int digitCounts[10] = {0};
    for (const char c : number)
        ++digitCounts[c - '0'];

    if (everyDigitCountIsOdd(digitCounts))
        return maxCountDigitStr(digitCounts);

    const std::string leftPart = findLeftPart(digitCounts),
                      rightPart = findRightPart(leftPart),
                      middlePart = findMiddlePart(digitCounts);
    return leftPart + middlePart + rightPart;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        std::string number;
        std::cin >> number;
        std::cout << wrongLargestPalindromicNumber(number) << std::endl;
        // printRightLargestPalindromicNumber(number);
    }

    return 0;
}
/*
// Print the digit if true
bool isOneDigit(const int *digitCounts)
{
    int digit = 0;
    for (int i = 1; i <= 9; ++i)
    {
        if (digitCounts[i] > 1)
            return false;
        if (digitCounts[i] == 1)
            digit = i;
    }
    std::cout << digit;
    return true;
}

void printRightLargestPalindromicNumber(const std::string &number)
{
    int digitCounts[10] = {0};
    for (const char c : number)
        ++digitCounts[c - '0'];

    if (isOneDigit(digitCounts))
        return;

    int maxCount = 0;
    int maxDigit = 0;
    for (int i = 9; i >= 0; --i)
    {
        if (digitCounts[i] % 2 == 0)
            digitCounts[i] /= 2;
        else
        {
            if (maxCount < digitCounts[i])
            {
                maxCount = digitCounts[i];
                maxDigit = i;
            }
            digitCounts[i] = 0;
        }
    }

    if (maxCount != 0)
        digitCounts[maxDigit] = (maxCount - 1) / 2;

    for (int i = 9; i >= 0; --i)
        for (int count = digitCounts[i]; count > 0; --count)
            std::cout << i;
    if (maxCount != 0)
        std::cout << maxDigit;
    for (int i = 0; i <= 9; ++i)
        for (int count = digitCounts[i]; count > 0; --count)
            std::cout << i;
}
*/