#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    long long n;
    std::vector<long long> A;

    while (t--) {
        std::cin >> n;
        A.resize(n);

        for (int i = 0; i < n; i++)
            std::cin >> A.at(i);

        std::cout << *std::max_element(A.begin(), A.end()) << '\n';
        A.clear();
    }

    return 0;
}