#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);

    while (n--)
        std::cin >> A.at(n);

    std::sort(A.begin(), A.end());

    auto last = std::unique(A.begin(), A.end());

    A.erase(last, A.end());

    for (auto x : A)
        std::cout << x << ' ';

    return 0;
}