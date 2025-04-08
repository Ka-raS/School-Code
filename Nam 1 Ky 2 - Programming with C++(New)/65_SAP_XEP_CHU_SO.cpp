#include <bits/stdc++.h>

int main() {
    int t, n, i;
    std::cin >> t;
    
    std::string S;
    
    while (t--) {
        std::cin >> i;
        std::cin.ignore();
        
        getline(std::cin, S);
        
        n = S.size();
        
        std::sort(S.begin(), S.end());
        
        i = 0;
        while (S[i] == ' ')
            i++;
                
        std::cout << S[i++] << ' ';
        
        while (i < n) {
            if (S[i] != S[i - 1])
                std::cout << S[i] << ' ';
                
            i++;
        }        
        
        std::cout << '\n';  
    }
    
    return 0;        
}