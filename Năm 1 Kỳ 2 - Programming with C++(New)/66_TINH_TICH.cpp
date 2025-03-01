#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    int i, n, m;
    long long tmp, min, max;
    
    while (t--) {
        std::cin >> n >> m >> max;
        
        for (i = 1; i < n; i++) {
            std::cin >> tmp;
            
            if (max < tmp)
                max = tmp;
        }        
        
        std::cin >> min;
        for (i = 1; i < m; i++) {
            std::cin >> tmp;
            
            if (min > tmp)
                min = tmp;
        }
        
        std::cout << max * min << '\n';  
    }
    
    return 0;        
}