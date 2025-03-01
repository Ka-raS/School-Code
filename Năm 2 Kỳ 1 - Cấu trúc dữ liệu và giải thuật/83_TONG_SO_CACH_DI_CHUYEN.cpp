#include <iostream>

int ways(const int n, const int k)
{
    int dp[n] = {0};
    const int M = 1e9 + 7;

    for (int i = n - 1; i >= 0; --i)
    {
        if (i >= n - k)
            ++dp[i];

        for (int j = 1; j <= k && i + j < n; ++j)
            dp[i] = ((long long)dp[i] + dp[i + j]) % M;
    }

    return dp[0];
}

void runProgram()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << ways(n, k) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}