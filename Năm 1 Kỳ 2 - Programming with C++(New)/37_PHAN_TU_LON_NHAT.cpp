#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n, i;
    std::vector<int> A;

    while (t--) {
        std::cin >> n;

        A.resize(n);

        for (i = 0; i < n; i++)
            std::cin >> A.at(i);

        std::cout << *std::max_element(A.begin(), A.end()) << '\n';

        A.clear();
    }

    return 0;
}