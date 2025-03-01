#include <iostream>

long long ans(unsigned long long a, unsigned long long b, const unsigned long long c)
{
    a = a % c;
    if (a <= UINT32_MAX && b <= UINT32_MAX)
        return a * b % c;

    long long res = 0;

    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % c;
        a = (a * 2) % c;
        b /= 2;
    }

    return res;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        unsigned long long a, b, c;
        std::cin >> a >> b >> c;

        // solve for a * b % c
        std::cout << ans(a, b, c) << std::endl;
    }

    return 0;
}