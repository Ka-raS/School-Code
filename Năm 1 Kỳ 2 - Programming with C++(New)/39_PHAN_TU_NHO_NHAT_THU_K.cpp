#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int i;
    int n, k;
    std::vector<int> A;

    while (t--) {
        std::cin >> n >> k;
        A.resize(n);

        for (i = 0; i < n; i++)
            std::cin >> A.at(i);

        std::sort(A.begin(), A.end());

        std::cout << A.at(k - 1) << '\n';

        A.clear();
    }

    return 0;
}