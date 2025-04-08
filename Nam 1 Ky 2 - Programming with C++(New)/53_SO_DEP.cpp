#include <bits/stdc++.h>

bool isPretty(std::string S) {
    int n = S.size();
    
    if (S.at(n / 2) & 1)
        return false;
    
    for (int i = 0; i < n / 2; i++) {
        if (S.at(i) != S.at(n - i - 1))
            return false;
        if (S.at(i) & 1)
            return false;
        if (S.at(n - i - 1) & 1)
            return false;
    }
    
    return true;           
}

int main() {
    int t;
    std::cin >> t;

    std::string S;
    
    while (t--) {
        std::cin >> S;
        
        if (isPretty(S))
            std::cout << "YES\n";
        else    
            std::cout << "NO\n";
    }
                
    return 0;        
}