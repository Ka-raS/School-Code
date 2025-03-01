#include <iostream>

int findSumDigits(int N)
{
    int res = 0;
    while (N)
    {
        res += N % 10;
        N /= 10;
    }
    return res;
}

int findSumPrimeDivisors(int N)
{
    if (N < 2)
        return 0;

    const int NOriginal = N;
    int res = 0;

    while (N % 2 == 0)
    {
        res += 2;
        N /= 2;
    }

    while (N % 3 == 0)
    {
        res += 3;
        N /= 3;
    }

    int i = 5;
    while (i * i <= N)
    {
        if (N % i == 0)
        {
            res += findSumDigits(i);
            N /= i;
        }
        else if (N % (i + 2) == 0)
        {
            res += findSumDigits(i + 2);
            N /= i + 2;
        }
        else
            i += 6;
    }

    if (N == NOriginal) // N is Prime
        return 0;
    if (N != 1)
        res += findSumDigits(N);
    return res;
}

bool isSmithNumber(const int &N)
{
    const int sumPrimeDivisors = findSumPrimeDivisors(N);
    if (sumPrimeDivisors == 0)
        return false;
    const int sumDigits = findSumDigits(N);
    return sumPrimeDivisors == sumDigits;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        long long N;
        std::cin >> N;
        if (isSmithNumber(N))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return 0;
}