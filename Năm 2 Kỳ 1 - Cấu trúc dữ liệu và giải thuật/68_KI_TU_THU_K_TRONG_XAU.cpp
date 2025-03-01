#include <iostream>
#include <array>

char doubleString(int n, long long k)
{
    const int pos = __builtin_ctzll(k) + 1; // position of the first 1 bit after a trail of 0 bits
    return pos + 64;
}

void runProgram()
{
    int n;
    long long k;
    std::cin >> n >> k;
    std::cout << doubleString(n, k) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}