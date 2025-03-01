#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    int n;
    
    while (t--) {
        std::string S;
        std::cin >> S;
            
        std::vector<int> count(26);
        
        for (auto c : S)
            count.at(c - 65)++;
        
        for (auto c : S)
            if (count.at(c - 65) == 1)
                std::cout << c;
                
        std::cout << '\n';
    }
            
    return 0;        
}