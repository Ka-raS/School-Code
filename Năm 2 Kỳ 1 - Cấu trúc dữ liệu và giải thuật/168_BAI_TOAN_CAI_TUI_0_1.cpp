#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t n, v;
int A[1000];
int C[1000];
int dp[1001][1000];

void run() {
    scanf("%d%d", &n, &v);
    for (size_t i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    for (size_t i = 0; i < n; ++i) {
        scanf("%d", &C[i]);
        dp[i][0] = 0;
    }
    dp[n][0] = 0;
    for (size_t i = 1; i <= v; ++i) {
        dp[0][i] = 0;
    }

    for (size_t i = 1; i <= n; ++i)
        for (size_t j = 1; j <= v; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (A[i - 1] <= j) {
                const int temp = C[i - 1] + dp[i - 1][j - A[i - 1]];
                if (temp > dp[i][j]) {
                    dp[i][j] = temp;
                }
            }
        }

    printf("%d\n", dp[n][v]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        run();
    }
}