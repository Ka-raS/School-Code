#include<bits/stdc++.h>

int main() {
    const int size = 17;
    std::vector<int> fib(size);
    fib[0] = 0, fib[1] = 1;

    for (int i = 2; i < size; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int t;
    std::cin >> t;

    int n, a;
    bool flag;

    while (t--) {
        std::cin >> n;

        while (n--) {
            std::cin >> a;

            for (auto x : fib) {
                if (x == a)
                    std::cout << a << ' ';
                if (x >= a)
                    break;
            }
        }

        std::cout << '\n';
    }

    return 0;
}