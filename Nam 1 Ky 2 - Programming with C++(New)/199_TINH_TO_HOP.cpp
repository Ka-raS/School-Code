#include <iostream>
#include <vector>
#include <algorithm>

void divide(std::vector<int> &A, int n)
{
    for (int &x : A)
    {
        const int div = std::__gcd(x, n);
        x /= div;
        n /= div;
        if (n == 1)
            return;
    }
}

int binomialCoefficient(const int &n, const int k)
{
    if (k == n || k == 0)
        return 1;
    if (k > n - k)
        return binomialCoefficient(n, n - k);

    std::vector<int> A;
    for (int i = 0; i < k; ++i)
        A.push_back(n - i);

    for (int i = 2; i <= k; ++i)
        divide(A, i);

    long long res = 1;
    for (const int &x : A)
        res = (res * x) % 1000000007;
    return res;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        std::cout << binomialCoefficient(n, k) << '\n';
    }

    return 0;
}