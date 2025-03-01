#include <iostream>
#include <cmath>

bool isPerfect(const long long &number)
{
    if (number > 1e12)
        return false;

    long long sumDivisors = 1;

    const long long root = std::ceil(std::sqrt(number));
    if (root * root == number)
        sumDivisors += root;

    for (long long divisor = 2; divisor < root; ++divisor)
        if (number % divisor == 0)
        {
            sumDivisors += divisor;
            sumDivisors += number / divisor;
        }

    return sumDivisors == number;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        long long number;
        std::cin >> number;
        std::cout << isPerfect(number) << std::endl;
    }

    return 0;
}