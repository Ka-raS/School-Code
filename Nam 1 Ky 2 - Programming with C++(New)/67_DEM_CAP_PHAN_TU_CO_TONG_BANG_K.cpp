#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    int n, k;
    int i, j, count;
    
    while (t--) {
        std::cin >> n >> k;
        
        std::vector<int> A(n);
        
        for (i = 0; i < n; i++)
            std::cin >> A[i];
        
        count = 0;    
        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++)
               if (A[i] + A[j] == k)
                   count++;
               
        std::cout << count << '\n';       
    }
    
    return 0;        
}