#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    long long n, i, j;
    
    while (t--) {
        std::cin >> n;
        
        std::vector<bool> A(n);
        
        for (i = 0; i < n; i++) {
            std::cin >> j;
            
            if (0 <= j && j < n)
                A[j] = 1;
        }        
        
        for (i = 0; i < n; i++) {
            if (A[i])
                std::cout << i << ' ';
            else
                std::cout << "-1 ";
        }            
               
        std::cout << '\n';       
    }
    
    return 0;        
}