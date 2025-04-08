#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    int n;
    
    int i;
    int count;
    
    while (t--) {
        std::cin >> n;
        std::vector<int> A(n);
        
        for (i = 0; i < n; i++)
            std::cin >> A.at(i);
            
        sort(A.begin(), A.end());
        
        n--;
        count = 0;
        
        for (i = 0; i < n; i++)
            if (A.at(i) == A.at(i + 1)) {
                count++;
                
                while (i < n && A.at(i) == A.at(i + 1)) {
                count++;
                i++;
                }
            }
           
        std::cout << count << '\n';
    }
            
    return 0;        
}