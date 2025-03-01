#include <bits/stdc++.h>

void input(std::vector<int> &A1, std::vector<int> &A2, int &n)
{
    auto inputArray = [&n](std::vector<int> &A)
    {
        A.clear();
        A.resize(n);

        for (size_t i = 0; i < n; i++)
            std::cin >> A[i];
    };

    std::cin >> n;
    inputArray(A1);
    inputArray(A2);
}

int findLen(const std::vector<int> A1, const std::vector<int> A2, const int n, const int m)
{
    int sumA1 = 0;
    int sumA2 = 0;
    int len = n - m;

    for (size_t i = m; i < n; i++)
    {
        sumA1 += A1[i];
        sumA2 += A2[i];
    }

    for (int i = n - 1; i >= m; i--)
    {
        if (sumA1 == sumA2)
            return len;
        else
        {
            len--;
            sumA1 -= A1[i];
            sumA2 -= A2[i];
        }
    }
}

int lenMax(const std::vector<int> A1, const std::vector<int> A2, const int n)
{
    int lenTmp;
    int lenMax = 0;

    for (int i = 0; i < n; i++)
    {
        if (lenMax > n - i)
            return lenMax;

        lenTmp = findLen(A1, A2, n, i);

        if (lenMax < lenTmp)
            lenMax = lenTmp;
    }

    return lenMax;
}

int main()
{
    int T;
    std::cin >> T;

    int n;
    std::vector<int> A1, A2;

    while (T--)
    {
        input(A1, A2, n);
        std::cout << lenMax(A1, A2, n) << '\n';
    }

    return 0;
}