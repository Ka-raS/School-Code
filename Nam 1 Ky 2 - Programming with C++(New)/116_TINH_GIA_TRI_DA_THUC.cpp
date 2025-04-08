#include <bits/stdc++.h>

int P(int n, int x) {
    const int mod = 1000000007;

    long long sum = 0, pro = 1;
    std::vector<long long> A(n);

    for (int i = 0; i < n; i++)
        std::cin >> A[i];

    while (n--) {
        sum = (sum + A[n] * pro) % mod;
        pro = (pro * x) % mod;
    }

    return sum;
}

int main() {
    int t, n, x;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> x;
        std::cout << P(n, x) << '\n';
    }

    return 0;
}