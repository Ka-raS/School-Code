#include <bits/stdc++.h>

bool notVowel(char c) {
    if (c == 'a' || c == 'A')
        return false;
    if (c == 'e' || c == 'E')
        return false;
    if (c == 'i' || c == 'I')
        return false;
    if (c == 'o' || c == 'O')
        return false;
    if (c == 'u' || c == 'U')
        return false;
    if (c == 'y' || c == 'Y')
        return false;
        
    return true;            
}

int main() {
    std::string S;
    std::cin >> S;
        
    int n = S.size();
    
    for (int i = 0; i < n; i++)
        if (notVowel(S[i]))
            std::cout << '.' << (char)tolower(S[i]);
    
    return 0;        
}