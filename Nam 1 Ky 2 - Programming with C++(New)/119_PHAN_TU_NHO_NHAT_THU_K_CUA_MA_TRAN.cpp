#include<bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n, k;

    while (t--) {
        std::cin >> n >> k;
        n *= n;
        std::vector<int> A(n);

        while (n--)
            std::cin >> A[n];

        std::sort(A.begin(), A.end());

        std::cout << A[k - 1] << '\n';
    }

    return 0;
}