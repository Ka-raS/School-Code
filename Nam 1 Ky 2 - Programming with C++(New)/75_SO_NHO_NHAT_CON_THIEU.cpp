#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    long long n, i, min;

    while (t--) {
        std::cin >> n;
        n--;
        
        std::vector<long long> A(n);

        for (i = 0; i < n; i++)
            std::cin >> A[i];

        min = 1;
        std::sort(A.begin(), A.end());

        for (i = 0; i < n && min >= A[i]; i++)
            if (min == A[i])
                min++;

        std::cout << min << '\n';
    }

    return 0;
}