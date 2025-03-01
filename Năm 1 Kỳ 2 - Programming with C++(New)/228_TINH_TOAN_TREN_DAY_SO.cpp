#include <bits/stdc++.h>

const int mod = 1e9 + 7;

void input(std::vector<int> &A, int &N)
{
    std::cin >> N;
    A.resize(N);

    for (int &x : A)
        std::cin >> x;
}

int pow(const int x, int y) // x^y
{
    long long product = 1;

    while (y--)
        product = (product * x) % mod;

    return product;
}

int product(const std::vector<int> &A)
{
    long long product = 1;

    for (int x : A)
        product = (product * x) % mod;

    return product;
}

int gcd(const std::vector<int> &A)
{
    int divisor = 0;

    for (int x : A)
        divisor = std::__gcd(x, divisor);

    return divisor;
}

int main()
{
    int T;
    std::cin >> T;

    int N;
    std::vector<int> A;

    while (T--)
    {
        input(A, N);
        int h = product(A),
            g = gcd(A);
        std::cout << pow(h, g) << '\n';
    }

    return 0;
}