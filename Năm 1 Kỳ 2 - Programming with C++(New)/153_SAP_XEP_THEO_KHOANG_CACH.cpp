#include <bits/stdc++.h>

int x;
bool cmp(const int a, const int b)
{
    return abs(a - x) < abs(b - x);
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n >> x;
        std::vector<int> A(n);
        for (int &val : A)
            std::cin >> val;

        std::stable_sort(A.begin(), A.end(), cmp);
        for (const int val : A)
            std::cout << val << ' ';
        std::cout << '\n';
    }

    return 0;
}