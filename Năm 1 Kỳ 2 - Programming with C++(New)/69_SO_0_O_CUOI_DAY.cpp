#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    
    long long n, count;
    
    while (t--) {
        std::cin >> n;
        
        std::vector<long long> A(n);
        
        count = 0;
        while (n--) {
            std::cin >> A[n];
            
            if (A[n])
                std::cout << A[n] << ' ';
            else
                count++;
        }            
        
        for (n = 0; n < count; n++)
            std::cout << "0 ";    
               
        std::cout << '\n';       
    }
    
    return 0;        
}