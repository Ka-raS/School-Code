#include <bits/stdc++.h>

void input(std::vector<int> &A, int &n)
{
    std::cin >> n;
    A.clear();
    A.resize(n);

    for (int i = 0; i < n; i++)
        std::cin >> A[i];
}

void merge(std::vector<int> &A, int &n, const int i, const int j)
{
    n--;
    A[j] += A[i];
    A.erase(A.begin() + i);
}

int mergesCount(std::vector<int> A, int n)
{
    int i = 0;
    int count = 0;

    while (i < n / 2)
    {
        if (A[i] < A[n - i - 1])
        {
            count++;
            merge(A, n, i, i + 1);
        }
        else if (A[i] > A[n - i - 1])
        {
            count++;
            merge(A, n, n - i - 1, n - i - 2);
        }
        else
            i++;
    }

    return count;
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
        std::cout << mergesCount(A, n) << '\n';
    }

    return 0;
}