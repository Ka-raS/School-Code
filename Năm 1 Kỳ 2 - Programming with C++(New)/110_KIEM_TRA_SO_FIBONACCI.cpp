#include <bits/stdc++.h>

int main() {
    std::vector<long long> fib;
    fib.push_back(0), fib.push_back(1);

    for (size_t i = 2; i <= 92; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    auto start = fib.begin(), end = fib.end();

    int t;
    std::cin >> t;

    long long n;

    while (t--) {
        std::cin >> n;
        auto iterator = std::find(start, end, n);

        iterator != end ? std::cout << "YES\n" : std::cout << "NO\n";
    }

    return 0;
}