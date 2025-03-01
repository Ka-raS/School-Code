#include <bits/stdc++.h>

void printAns(std::vector<long long> A, long long n) {
    for (int i = 1; i < n; i++)
        if (A[i] > A[0]) {
            std::cout << A[0] << "  " << A[i] << '\n';
            return;
        }
    
    std::cout << "-1\n";
}

int main() {
    int t;
    std::cin >> t;

    long long n, i;
    while (t--) {
        std::cin >> n;
        std::vector<long long> A(n);

        for (i = 0; i < n; i++)
            std::cin >> A[i];
        
        std::sort(A.begin(), A.end());

        printAns(A, n);
    }

    return 0;
}