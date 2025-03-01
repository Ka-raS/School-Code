#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    long long n, x, i;
    while (t--) {
        std::cin >> n >> x;
        std::vector<long long> A(n);

        for (i = 0; i < n; i++) {
            std::cin >> A[i];

            if (A[i] == x)
                std::cout << i + 1 << '\n';
        }        
    }

    return 0;
}