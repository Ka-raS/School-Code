#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        int X[n];

        for (int i = 0; i < n; i++)
            std::cin >> X[i];

        std::prev_permutation(X, X + n);

        for (auto i : X)
            std::cout << i << "  ";
        std::cout << '\n';
    }

    return 0;
}