#include <iostream>
#include <vector>

int sharedSubStringSize(const std::string &str1, const std::string &str2)
{
    const size_t n = str1.size();
    const size_t m = str2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
        {
            if (str1[i] == str2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
        }

    return dp[n][m];
}

void runProgram()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << sharedSubStringSize(str1, str2) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}