#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    int count;
    std::string S, buf;
    
    while (t--) {
        getline(std::cin, S);
            
        std::stringstream ss(S);
        
        count = 0;
        while (ss >> buf)
            count++;
                
        std::cout << count << '\n';
    }
            
    return 0;        
}