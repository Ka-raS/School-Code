#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    int k, n;
    
    while (t--) {
        std::cin >> k >> n;
        n += k;
        
        std::vector<int> A(n);
        
        while (n--)
            std::cin >> A[n];
            
        std::sort(A.begin(), A.end());
        
        for (auto i : A)
            std::cout << i << ' ';
            
        std::cout << '\n';       
    }
    
    return 0;        
}