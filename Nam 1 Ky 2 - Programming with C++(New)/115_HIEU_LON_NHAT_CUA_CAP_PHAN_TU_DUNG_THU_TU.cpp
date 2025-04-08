#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n, i, j;
    int min, max, dif;

    while (t--) {
        std::cin >> n;
        std::vector<int> A(n);

        for (i = 0; i < n; i++)
            std::cin >> A[i];

        dif = 0;

        for (i = n - 1; i > 0; i--)
            for (j = i - 1; j >= 0; j--)
                if (dif < A[i] - A[j])
                    dif = A[i] - A[j];

        if (dif == 0)
            std::cout << -1;
        else
            std::cout << dif;
        std::cout << '\n';
    }

    return 0;
}