#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n, i, x, min;
    std::vector<int> A;

    while (t--) {
        std::cin >> n;

        for (i = 0; i < n; i++) {
            std::cin >> x;

            if (x > 0)
                A.push_back(x);
        }

        min = 1;
        std::sort(A.begin(), A.end());

        for (i = 0; i < n && min >= A.at(i); i++)
            if (min == A.at(i))
                min++;
        
        std::cout << min << '\n';
        A.clear();
    }

    return 0;
}