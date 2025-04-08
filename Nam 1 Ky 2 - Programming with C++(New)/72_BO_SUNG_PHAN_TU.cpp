#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    int n, i, j, count;
    
    while (t--) {
        std::cin >> n;
        std::vector<int> A(n);

        for (i = 0; i < n; i++)
            std::cin >> A[i];

        std::sort(A.begin(), A.end());

        count = 0;

        for (i = 1; i < n; i++) {
            j = A[i] - A[i - 1];

            if (j > 1)
                count += j - 1;
        }
        
        std::cout << count << '\n';       
    }
    
    return 0;        
}