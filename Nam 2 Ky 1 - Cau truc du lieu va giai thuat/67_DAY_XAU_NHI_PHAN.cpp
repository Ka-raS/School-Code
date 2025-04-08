#include <iostream>
#include <array>

void findFib(std::array<long long, 94> &fib)
{
    fib[0] = 0;
    fib[1] = 1;
    for (size_t i = 2; i < 94; ++i)
        fib[i] = fib[i - 2] + fib[i - 1];
}

int fibNum(int n, long long k, const std::array<long long, 94> &fib)
{
    while (n > 2)
    {
        if (k > fib[n - 2])
        {
            k -= fib[n - 2];
            ++n;
        }
        else
            n -= 2;
    }
    return n - 1;
}

void runProgram(const std::array<long long, 94> &fib)
{
    int n;
    long long k;
    std::cin >> n >> k;
    std::cout << fibNum(n, k, fib) << '\n';
}

int main()
{
    std::array<long long, 94> fib;
    findFib(fib);

    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram(fib);
}