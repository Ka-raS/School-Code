#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    bool flag;
    int n, i, count;

    while (t--) {
        std::cin >> n;
        std::vector<int> A(1000001);

        flag = 1;

        while (n--) {
            std::cin >> i;

            if (flag) {
                if (A[i]) {
                    std::cout << i << '\n';
                    flag = 0;
                }
                else
                    A[i] = 1;
            }
        }

        if (flag)
            std::cout << "-1\n";
    }

    return 0;
}