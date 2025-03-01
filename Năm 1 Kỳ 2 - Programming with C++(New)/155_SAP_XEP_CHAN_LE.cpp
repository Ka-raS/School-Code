#include <bits/stdc++.h>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int &x : A)
            std::cin >> x;

        const int m = n / 2 + (n % 2);
        int i = 0, j = m;
        std::sort(A.begin(), A.end());

        while (i < m && j < n)
        {
            std::cout << A[i] << ' ' << A[j] << ' ';
            if (i <= m)
                i++;
            if (j <= n)
                j++;
        }
        if (i < m)
            std::cout << A[i] << ' ';
        if (j < n)
            std::cout << A[j] << ' ';

        std::cout << '\n';
    }

    return 0;
}