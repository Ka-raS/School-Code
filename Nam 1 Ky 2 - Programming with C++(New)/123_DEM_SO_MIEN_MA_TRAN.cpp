#include<bits/stdc++.h>
#define size 200

void connect(int A[size][size], const int n, const int m) {
    A[n][m] = 0;
    int i, j;

    for (i = n - 1; i < n + 2; i++)
        for (j = m - 1; j < m + 2; j++)
            if (A[i][j])
                connect(A, i, j);
}

int main() {
    int t;
    std::cin >> t;

    int i, j;
    int n, m;
    int regions;

    while (t--) {
        std::cin >> n >> m;

        int A[size][size];
        regions = 0;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                std::cin >> A[i][j];
                
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                if (A[i][j]) {
                    regions++;
                    connect(A, i, j);
                }
                
        std::cout << regions << '\n';
    }

    return 0;
}