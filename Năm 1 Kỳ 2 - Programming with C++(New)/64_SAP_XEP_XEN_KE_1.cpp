#include <bits/stdc++.h>

int main() {
    int t, n, i;
    std::cin >> t;
    
    while (t--) {
        std::cin >> n;
        std::vector<int> A(n);
        
        for (i = 0; i < n; i++)
            std::cin >> A[i];
        
        std::sort(A.begin(), A.end());
        
        for (i = 0; i < n / 2; i++)
            std::cout << A[n - i - 1] << ' ' << A[i] << ' ';
        
        if (n & 1)
            std::cout << A[i];
            
        std::cout << '\n';  
    }
    
    return 0;        
}