#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    int i;
    int n, d;
    std::vector<int> A;

    while (t--) {
        std::cin >> n >> d;
        A.resize(n);

        for (i = 0; i < n; i++)
            std::cin >> A.at(i);

        for (i = d; i < n; i++)
            std::cout << A.at(i) << ' ';

        for (i = 0; i < d; i++) 
            std::cout << A.at(i) << ' ';

        std::cout << '\n';
        A.clear();
    }

    return 0;
}