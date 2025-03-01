#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d\n", &t);

    int dp[1001][1001];
    char s1[1001], s2[1001];

    while (t--) {
        memset(dp, 0, sizeof(dp));
        fgets(s1, 1001, stdin);
        fgets(s2, 1001, stdin);

        int i, j;
        for (i = 0; s1[i] != '\n'; ++i) {
            for (j = 0; s2[j] != '\n'; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else if (dp[i][j + 1] > dp[i + 1][j]) {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                } else {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
            }
        }

        printf("%d\n", dp[i][j]);
    }
}