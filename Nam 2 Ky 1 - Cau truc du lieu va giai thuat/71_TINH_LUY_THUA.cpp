#include <iostream>

int power(long long base, long long exponent)
{
    long long result = 1;
    const int modulus = 1e9 + 7;

    while (exponent > 0)
    {
        if (exponent % 2 != 0)
            result = result * base % modulus;
        base = base * base % modulus;
        exponent /= 2;
    }

    return result;
}

void runProgram()
{
    while (true)
    {
        long long base, exponent;
        std::cin >> base >> exponent;

        if (base == 0 && exponent == 0)
            break;

        std::cout << power(base, exponent) << '\n';
    }
}

int main()
{
    runProgram();
}