#include <bits/stdc++.h>

bool isSatisfied(std::string S) {
    int k = 1;
    int sum = 0;
    int n = S.size();
    
    while (n--) {
        if (k == 5)
            k = 1;
            
        if (S.at(n) == '1') {
            sum += k;
            
            if (k == 3)
                sum++;
            else if (k == 4)
                sum--;    
        }    
            
        k++;    
    }    
        
    return sum % 5 == 0;           
}

int main() {
    int t;
    std::cin >> t;

    std::string S;
    
    while (t--) {
        std::cin >> S;
        
        if (isSatisfied(S))
            std::cout << "Yes\n";
        else
            std::cout << "No\n";    
    }
    return 0;        
}