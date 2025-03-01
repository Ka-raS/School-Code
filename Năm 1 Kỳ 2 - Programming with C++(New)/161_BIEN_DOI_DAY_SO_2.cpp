#include <iostream>
#include <vector>

std::vector<long long> solve(const std::vector<int> &A)
{
    int n = A.size();
    if (n == 1)
        return {A[0]};

    std::vector<long long> Ans(n);
    Ans[0] = A[0] * A[1];
    Ans[n - 1] = A[n - 1] * A[n - 2];

    for (size_t i = 1; i < n - 1; i++)
        Ans[i] = A[i - 1] * A[i + 1];

    return Ans;
}

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

        std::vector<long long> Ans = solve(A);
        for (const long long x : Ans)
            std::cout << x << ' ';
        std::cout << '\n';
    }

    return 0;
}