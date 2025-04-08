#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n, x, i, count;

    while (t--) {
        std::cin >> n >> x;

        count = 0;

        while (n--) {
            std::cin >> i;

            if (i == x)
                count++;
        }

        if (count)
            std::cout << count << '\n';
        else
            std::cout << "-1\n";
    }

    return 0;
}