#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n, k, i;

    while (t--) {
        std::cin >> n >> k;

        std::vector<int> A(n);

        for (i = 0; i < n; i++)
            std::cin >> A[i];

        std::sort(A.begin(), A.end(), std::greater<int>());

        for (i = 0; i < k; i++)
            std::cout << A[i] << ' ';
        
        std::cout << '\n';
    }

    return 0;
}