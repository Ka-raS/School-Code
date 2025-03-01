#include <bits/stdc++.h>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int t;
    std::cin >> t;

    int count;
    int M, N, A, B;

    while (t--) {
        std::cin >> M >> N >> A >> B;

        if (M > N)
            swap(M, N);

        count = 0;

        for (int i = M; i <= N; i++)
            count += !(i % A) || !(i % B);

        std::cout << count << '\n';
    }

    return 0;
}