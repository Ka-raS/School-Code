// fibStr(1) == "A"
// fibStr(2) == "B"
// fibStr(n) == fibStr(n - 2) + fibStr(n - 1)
// find fibStr(n).at(i - 1)

#include <iostream>
#include <array>

void findFibonacci(std::array<long long, 94> &fib)
{
    fib[0] = 0;
    fib[1] = 1;
    for (size_t i = 2; i < 94; ++i)
        fib[i] = fib[i - 2] + fib[i - 1];
}

char fibStr(int n, long long i, const std::array<long long, 94> &fib)
{
    while (n > 2)
    {
        if (i <= fib[n - 2])
            n -= 2;
        else
        {
            i -= fib[n - 2];
            --n;
        }
    }

    if (n == 1)
        return 'A';
    return 'B';
}

int main()
{
    std::array<long long, 94> fib;
    findFibonacci(fib);

    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
    {
        int n;
        long long i;
        std::cin >> n >> i;
        std::cout << fibStr(n, i, fib) << '\n';
    }
}
