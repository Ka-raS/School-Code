#include <iostream>
#include <cmath>

bool isPrime(const int &N)
{
    if (N <= 1)
        return false;
    if (N <= 3)
        return true;
    if (N % 2 == 0 || N % 3 == 0)
        return false;
    for (int i = 5; i * i <= N; i += 6)
        if (N % i == 0 || N % (i + 2) == 0)
            return false;
    return true;
}

int countThreeDivisorsNumbers(const long long &L, const long long &R)
{
    int count = 0;
    if (L <= 4)
        ++count;

    // N = i * i
    long long i = 3;
    while (i * i < L)
        i += 2;
    // N is now >= L
    while (i * i <= R)
    {
        if (isPrime(i))
            ++count;
        i += 2;
    }

    return count;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        long long L, R;
        std::cin >> L >> R;
        const int count = countThreeDivisorsNumbers(L, R);
        std::cout << count << std::endl;
    }

    return 0;
}