#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n, i, j;
    std::vector<int> A;

    while (t--) {
        std::cin >> n;
        A.resize(n);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                std::cin >> A.at(j);

            if (i & 1) {
                for (j = n - 1; j >= 0; j--)
                    std::cout << A.at(j) << ' ';
            } else {
                for (j = 0; j < n; j++)
                    std::cout << A.at(j) << ' ';
            }
        }

        std::cout << '\n';
        A.clear();
    }

    return 0;
}