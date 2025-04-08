#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    
    int n, i, j, count;
    std::string S;
    
    while (t--) {
        std::cin >> S;
        
        n = S.size();
        count = 0;
        
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (S[i] == S[j])
                    count++;
                    
        std::cout << n + count << '\n';
    }
    
    return 0;        
}