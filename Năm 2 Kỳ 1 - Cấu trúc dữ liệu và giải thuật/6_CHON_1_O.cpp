#include <iostream>
#include <vector>

void input(std::vector<std::vector<int>> &);
int maxSum(const std::vector<std::vector<int>> &);

int main()
{
    int testCases;
    std::cin >> testCases;
    for (int test = 0; test < testCases; ++test)
    {
        std::vector<std::vector<int>> Matrix;
        input(Matrix);
        std::cout << maxSum(Matrix) << std::endl;
    }
}

void input(std::vector<std::vector<int>> &A)
{
    std::size_t n;
    std::cin >> n;
    A.resize(n, std::vector<int>(n));

    for (std::size_t i = 0; i < n; ++i)
        for (std::size_t j = 0; j < n; ++j)
            std::cin >> A[i][j];
}

int maxSum(const std::vector<std::vector<int>> &A)
{
    // bitmask

    const int n = A.size();
    std::vector<int> dp(1 << n, INT32_MIN); // 1 << n = 2^n
    dp[0] = 0;                              // dp[0]: 0 rows included => sum = 0

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        const int i = __builtin_popcount(mask); // current row = bitsets in mask
        if (i >= n)                             // if row index >= n
            continue;

        for (int j = 0; j < n; ++j)
            if ((mask & (1 << j)) == 0) // if column j not included
                dp[mask | (1 << j)] = std::max(dp[mask | (1 << j)], dp[mask] + A[i][j]);
    }

    return dp[(1 << n) - 1];
}