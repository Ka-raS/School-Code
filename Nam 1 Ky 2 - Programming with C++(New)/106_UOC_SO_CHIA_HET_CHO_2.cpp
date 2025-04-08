#include <bits/stdc++.h>

int divisors(const int n) {
    if (n & 1)
        return 0;

    int count = 1;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            if (i % 2 == 0)
                count++;
                
            if (n / i != i && (n / i) % 2 == 0)
                count++;
        }

    return count;
}

int main() {
    int t, n;
    std::cin >> t;

    while (t--) {
        std::cin >> n;
        std::cout << divisors(n) << '\n';
    }

    return 0;
}