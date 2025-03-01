#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();

    int n, i;
    std::string S, buf;
    std::vector<std::string> reverseS;
    
    while (t--) {
        std::getline(std::cin, S);
        
        std::stringstream ss(S);
        
        while (ss >> buf)
            reverseS.push_back(buf);
        
        n = reverseS.size();
        
        for (int i = n - 1; i >= 0; i--)
            std::cout << reverseS[i] << ' ';
        std::cout << '\n';
        
        reverseS.clear();
    }

    return 0;
}