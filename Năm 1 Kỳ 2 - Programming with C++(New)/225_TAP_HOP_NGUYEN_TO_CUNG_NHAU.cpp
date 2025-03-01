#include <bits/stdc++.h>

bool isSatisfied(long long n, long long m)
{
    long long sumAll = n * (n + 1) / 2;
    if (sumAll < m)
        return false;

    long long sum1 = (sumAll + m) / 2,
              sum2 = sumAll - sum1,
              sumsAbs = sum1 - sum2;

    bool isDividable = sum1 + sum2 == sumAll;
    if (isDividable == false)
        return false;
    if (sumsAbs != m)
        return false;

    bool isCoprime = std::__gcd(sum1, sum2) == 1;
    return isCoprime;
}

int main()
{
    int T;
    std::cin >> T;

    long long n, m;

    while (T--)
    {
        std::cin >> n >> m;

        if (isSatisfied(n, m))
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    return 0;
}