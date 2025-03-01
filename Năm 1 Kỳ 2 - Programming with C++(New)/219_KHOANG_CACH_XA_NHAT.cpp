#include <bits/stdc++.h>

void input(std::vector<int> &A, int &n)
{
    std::cin >> n;
    A.clear();
    A.resize(n);

    for (size_t i = 0; i < n; i++)
        std::cin >> A[i];
}

int largestDistance(const std::vector<int> A, const int n)
{
    int max = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (max > n - i)
            break;

        for (int j = n - 1; j > i; j--)
            if (max < j - i && A[i] <= A[j])
                max = j - i;
    }

    return max;
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
        std::cout << largestDistance(A, n) << '\n';
    }

    return 0;
}