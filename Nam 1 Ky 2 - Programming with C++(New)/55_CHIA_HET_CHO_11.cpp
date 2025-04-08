#include <bits/stdc++.h>

bool isSatisfied(std::string S) {
    int sum = 0;
    int n = S.size();
    
    for (int i = 0; i < n; i++) {
        if ((n - i) & 1)
            sum += S.at(i) - 48;
        else    
            sum += -S.at(i) + 48 + 11;
    }    
        
    return sum % 11 == 0;           
}

int main() {
    int t;
    std::cin >> t;

    std::string S;
    
    while (t--) {
        std::cin >> S;
        
        std::cout << isSatisfied(S) << '\n';
    }
    return 0;        
}