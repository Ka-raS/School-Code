#include <bits/stdc++.h>

void input(std::vector<int> &A, int &n)
{
    std::cin >> n;
    A.resize(n);

    for (int &x : A)
        std::cin >> x;
}

int findGcdAbs(const std::vector<int> &A)
{
    int gcd = 0,
        min = *std::min_element(A.begin(), A.end());

    for (int num : A)
        gcd = std::__gcd(gcd, abs(num - min));

    return gcd;
}

int K(const int gcdAbs)
{
    int divisor,
        divisorsCount = 0;

    for (divisor = 1; divisor * divisor < gcdAbs; divisor++)
        if (gcdAbs % divisor == 0)
            divisorsCount += 2;

    if (divisor * divisor == gcdAbs)
        divisorsCount++;

    return divisorsCount;
}

int main()
{
    int T;
    std::cin >> T;

    int n;
    std::vector<int> A;

    while (T--)
    {
        input(A, n);
        int gcdAbs = findGcdAbs(A);
        std::cout << K(gcdAbs) << '\n';
    }

    return 0;
}

/* Cách 2 dễ hiểu hơn

void input(std::vector<int> &A, int &n)
{
    std::cin >> n;
    A.clear();
    A.resize(n);

    for (int &x : A)
        std::cin >> x;
}

bool isEqualRemainders(const std::vector<int> A, const int n, const int divisor)
{
    for (int num : A)
        if ((num - A[0]) % divisor != 0)
            return false;

    return true;
}

int K(const std::vector<int> A, const int n)
{
    int divisorsCount = 0,
        max = A[n - 1] - A[0];

    for (int divisor = 1; divisor <= max; divisor++)
        if (isEqualRemainders(A, n, divisor))
            divisorsCount++;

    return divisorsCount;
}

int main()
{
    int T;
    std::cin >> T;

    int n;
    std::vector<int> A;

    while (T--)
    {
        input(A, n);
        std::sort(A.begin(), A.end());
        std::cout << K(A, n) << '\n';
    }

    return 0;
}
*/