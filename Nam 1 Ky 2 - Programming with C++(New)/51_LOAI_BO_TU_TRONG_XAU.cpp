#include <bits/stdc++.h>

int main() {
    std::string S, word, buf;
    
    getline(std::cin, S);
    std::cin >> word;
    
    std::stringstream ss(S);
    
    while (ss >> buf)
        if (buf != word)
            std::cout << buf << ' ';
            
    return 0;        
}