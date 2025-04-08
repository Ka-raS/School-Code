#include <bits/stdc++.h>

bool isDominance(std::string S) {
    int odds = 0, evens = 0, n = 0;
    std::string buf;
    std::stringstream ss(S);
    
    while (ss >> buf) {
        n++;
        if (std::stoi(buf) & 1)
            odds++;
        else
            evens++;    
    }
    
    if (odds > evens && (n & 1))
        return true;
    if (evens > odds && (n & 1) == 0)
        return true;
    return false;        
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    std::string S;
    
    while (t--) {
        getline(std::cin, S);
        
        if (isDominance(S))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";    
    }
    
    return 0;        
}