#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string num(n, '0');
        std::cout << num << ' ';

        int i = n - 1;
        while (i >= 0) {
            if (num[i] == '0') {
                num[i] = '1';
                i = n - 1;
                std::cout << num << ' ';
            } else {    // if (num[i] == '1')
                num[i] = '0';
                i--;
            }
        }

        std::cout << '\n';
    }

    return 0;
}