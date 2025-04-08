#include <iostream>

bool isDividable(const std::string &str, const long long divisor)
{
    long long remainder = 0;
    for (const char c : str)
    {
        const int digit = c - '0';
        remainder = remainder * 10 + digit;
        remainder %= divisor;
    }
    return remainder == 0;
}

long long greatestCommonDivisor(const long long A, const std::string &B)
{
    long long maxDivisor;
    for (long long d = 1; d * d <= A; ++d)
        if (A % d == 0)
        {
            if (isDividable(B, A / d))
                return A / d;
            if (isDividable(B, d))
                maxDivisor = d;
        }
    return maxDivisor;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        long long A;
        std::string B;
        std::cin >> A >> B;
        std::cout << greatestCommonDivisor(A, B) << std::endl;
    }
    return 0;
}