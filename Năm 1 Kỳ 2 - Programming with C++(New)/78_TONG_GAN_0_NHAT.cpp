#include <bits/stdc++.h>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    int n, i, j, sum, min;

    while (t--) {
        std::cin >> n;
        std::vector<int> A(n);

        for (i = 0; i < n; i++)
            std::cin >> A[i];
        
        min = A[0] + A[1];

        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++) {
                sum = A[i] + A[j];

                if (abs(min) > abs(sum))
                    min = sum;
            }

        std::cout << min << '\n';
    }

    return 0;
}