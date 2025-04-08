#include <iostream>
#include <vector>

std::vector<int> findFib()
{
    const int mod = 1000000007;
    const size_t SIZE = 1001;
    std::vector<int> fib(SIZE);
    fib[0] = 0, fib[1] = 1;

    for (size_t i = 2; i < SIZE; ++i)
    {
        long long val = fib[i - 1];
        val = (val + fib[i - 2]) % mod;
        fib[i] = val;
    }

    return fib;
}

int main()
{
    std::vector<int> fib = findFib();

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::cout << fib[n] << std::endl;
    }

    return 0;
}