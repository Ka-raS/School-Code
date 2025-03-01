#include <bits/stdc++.h>

bool isPangram(std::string S, int k) {
    int n = S.size();
    if (n < 26)
        return false;
        
    std::vector<bool> flag(26);
    
    for (auto c : S)
        flag.at(c - 97) = 1;
        
    int count = 0;
    
    for (auto x : flag)
        if (x)
            count++;
            
    if (count + k >= 26)
        return true;
    return false;        
}

int main() {
    int t;
    std::cin >> t;
    
    int k;
    std::string S;
    
    while (t--) {
        std::cin >> S >> k;
                
        std::cout << isPangram(S, k) << '\n';
    }
            
    return 0;        
}