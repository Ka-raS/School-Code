#include<bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    const int size = 100001;
    int n, x, i, j, sum;

    while (t--) {
        std::cin >> n;
        std::vector<int> count(size);

        for (j = 0; j < n; j++)
            for (i = 0; i < n; i++) {
                std::cin >> x;

                if (count[x] == j)
                    count[x]++;
            }

        sum = 0;

        for (i = 1; i < size; i++)
            if (count[i] == n)
                sum++;
        std::cout << sum << '\n';
    }

    return 0;
}