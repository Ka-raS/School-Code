#include <iostream>

int powerModulus(long long base, long long exponent, const int modulus)
{
    long long result = 1;
    base %= modulus;

    while (exponent != 0)
    {
        if (exponent % 2 == 1)
            result = result * base % modulus;
        base = base * base % modulus;
        exponent /= 2;
    }

    return result;
}

int countNumbersHasDigitsSum(const long long digitsSum)
{
    const int base = 2;
    const long long exponent = digitsSum - 1;
    const int modulus = 123456789;

    return powerModulus(base, exponent, modulus);
}

void runProgram()
{
    long long digitsSum;
    std::cin >> digitsSum;
    std::cout << countNumbersHasDigitsSum(digitsSum) << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}