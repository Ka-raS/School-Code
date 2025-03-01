#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n, i, j;
    std::vector< std::vector<int> > A(100, std::vector<int>(100));

    while (t--) {
        std::cin >> n;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                std::cin >> A[i][j];
                
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                    std::cout << A[i][j] << ' ';
                else
                    std::cout << "  ";
            }

            std::cout << '\n';
        }                
    }

    return 0;
}