#include <bits/stdc++.h>

int main() {
    std::string S, buf;
    getline(std::cin, S);
    
    std::stringstream ss(S);
    
    int n = 0;
    std::vector<std::string> A;
    
    while (ss >> buf) {
        n++;
        A.push_back(buf);
    }
    
    int i, j;
    int m;
    n -= 2;
    
    for (i = 0; i < n; i++) {
        std::cout << (char)toupper(A[i][0]);
        
        m = A[i].size();
        
        for (j = 1; j < m; j++)
            std::cout << (char)tolower(A[i][j]);
            
        std::cout << ' ';    
    }
    
    std::cout << (char)toupper(A[i][0]);
        
    m = A[i].size();
        
    for (j = 1; j < m; j++)
        std::cout << (char)tolower(A[i][j]);
    
    std::cout << ", ";            
    
    i++;
    m = A[i].size();
    
    for (j = 0; j < m; j++)
        std::cout << (char)toupper(A[i][j]);
    
    return 0;        
}