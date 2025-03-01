#include <bits/stdc++.h>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<bool> A(100001);
        while (n--)
        {
            int i;
            std::cin >> i;
            A[i] = 1;
        }

        std::set<int> B;
        while (m--)
        {
            int i;
            std::cin >> i;
            if (A[i])
                B.insert(i);
            else
                A[i] = 1;
        }

        for (int i = 0; i < 100001; i++)
            if (A[i])
                std::cout << i << ' ';
        std::cout << '\n';

        for (const int i : B)
            std::cout << i << ' ';
        std::cout << '\n';
    }

    return 0;
}