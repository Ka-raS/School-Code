#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    bool flag;
    int n, X, i;

    while (t--) {
        std::cin >> n >> X;
        std::vector<int> A(n);

        flag = 1;

        for (i = 0; i < n; i++) {
            std::cin >> A[i];

            if (flag && A[i] == X) {
                std::cout << i + 1 << '\n';
                flag = 0;
            }
        }

        if (flag)
            std::cout << "-1\n";
    }

    return 0;
}