#include <iostream>

long long reverse(long long number)
{
    long long reverseNumber = 0;
    while (number > 0)
    {
        const long long digit = number % 10;
        number /= 10;
        reverseNumber = reverseNumber * 10 + digit;
    }
    return reverseNumber;
}

// đề sai
// int power(long long base, long long exponent)
// {
//     long long result = 1;
//     const int modulo = 1e9 + 7;
//     base %= modulo;

//     while (exponent != 0)
//     {
//         if (exponent % 2 == 1)
//             result = result * base % modulo;
//         base = base * base % modulo;
//         exponent /= 2;
//     }

//     return result;
// }

const int modulo = 1e9 + 7;
long long power(const long long base, const long long exponent)
{
    if (exponent == 0)
        return 1;

    long long exponential = power(base, exponent / 2);
    exponential = exponential * exponential % modulo;

    if (exponent % 2 == 1)
        exponential = base * exponential % modulo;

    return exponential;
}

void runProgram()
{
    long long number;
    std::cin >> number;
    const long long reverseNumber = reverse(number);
    std::cout << power(number, reverseNumber) << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}