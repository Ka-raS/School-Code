#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    int n, i;
    long long min;
    long long A[100000];

    while (t--) {
        std::cin >> n;

        for (i = 0; i < n; i++)
            std::cin >> A[i];

        std::sort(A, A + n, std::greater<long long>());

        min = A[0] - A[1];

        for (i = 2; i < n && min; i++)
            if (min > A[i - 1] - A[i])
                min = A[i - 1] - A[i];

        std::cout << min << '\n';
    }

    return 0;
}