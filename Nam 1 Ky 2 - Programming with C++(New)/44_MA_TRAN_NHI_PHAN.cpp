#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    int count = 0;
    int i, x, flag;

    while (n--) {
        flag = 0;

        for (i = 0; i < 3; i++) {
            std::cin >> x;
            flag += x;
        }

        if (flag > 1)
            count++;
    }

    std::cout << count;

    return 0;
}