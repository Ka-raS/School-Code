#include <bits/stdc++.h>

int main() {
    int t, n;
    std::cin >> t;
    
    while (t--) {
        std::cin >> n;
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