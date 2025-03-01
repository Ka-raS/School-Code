#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >>n;
    std::cin.ignore();

    std::vector<std::string> S(n);
    
    int i, j;
    for (i = 0; i < n; i++)
        getline(std::cin, S.at(i));
    
    int count = 0;
    for (i = 0; i < n; i++) {
        count++;
        
        for (j = i + 1; j < n; j++)
            if (S.at(i) == S.at(j)) {
                count--;
                break;
            }
    }
    
    std::cout << count;
                
    return 0;        
}