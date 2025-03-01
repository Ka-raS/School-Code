#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    long long a, x, y, loop;

    while (t--) {
        std::cin >> a >> x >> y;

        loop = std::__gcd(x, y);

        while (loop--)
            std::cout << a;
        std::cout << '\n';
    }

    return 0;
}