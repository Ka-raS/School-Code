#include <bits/stdc++.h>

bool isMountainSequence(std::vector<int> A, int i, int n) {
    if (i == n)
        return true;
        
    if (i + 1 == n) {
        if (A[i] < A[i + 1])
            return true;
        else
            return false;
    }                

    while (A[i] == A[i + 1] && i < n)
        i++;
        
    if (A[i] > A[i + 1] || i == n)
        return false;
        
    while (A[i] <= A[i + 1] && i < n)
        i++;
        
    if (i == n)
        return false;
        
    while (A[i] >= A[i + 1] && i < n)
        i++;
    
    if (i == n)
        return true;    
        
    return false;            
}

int main() {
    int t;
    std::cin >> t;

    int n, L, R;

    while (t--) {
        std::cin >> n;
        std::vector<int> A(n);

        for (int i = 0; i < n; i++)
            std::cin >> A[i];
            
        std::cin >> L >> R;
        
        if (isMountainSequence(A, L, R))
            std::cout << "Yes";
        else
            std::cout << "No";
        std::cout << '\n';
    }

    return 0;
}