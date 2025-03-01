#include <bits/stdc++.h>
#include <cctype>

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
    
    n--;
    int m = A[n].size();
    
    while (m--)
        A[n][m] = tolower(A[n][m]);
    
    std::cout << A[n];
    
    for (int i = 0; i < n; i++)
        std::cout << (char)tolower(A[i][0]);
    
    std::cout << "@ptit.edu.vn";
    
    return 0;        
}