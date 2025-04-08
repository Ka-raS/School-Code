#include <iostream>

int pow(long long base, long long exponent)
{
    long long result = 1;
    const int modulo = 1e9 + 7;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulo;
        base = (base * base) % modulo;
        exponent /= 2;
    }

    return result;
}

void runProgram()
{
    int base, exponent;
    std::cin >> base >> exponent;
    std::cout << pow(base, exponent) << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}