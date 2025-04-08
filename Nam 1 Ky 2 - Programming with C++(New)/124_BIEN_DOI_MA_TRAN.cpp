#include<bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int n;
    int i, j;
    int sumMax, sumAll, sumTmp;

    while (t--) {
        std::cin >> n;

        int A[n][n];
        
        sumMax = 0;
        sumAll = 0;
        sumTmp = 0;
        
        
        for (i = 0; i < n; i++) {
            sumTmp = 0;
            
            for (j = 0; j < n; j++) {
                std::cin >> A[i][j];
                sumTmp += A[i][j];
            }

            sumAll += sumTmp;
            
            if (sumMax < sumTmp)
                sumMax = sumTmp;
            
        }

        for (j = 0; j < n; j++) {
            sumTmp = 0;
            
            for (i = 0; i < n; i++)
                sumTmp += A[i][j];
                
            sumAll += sumTmp;    
                
            if (sumMax < sumTmp)
                sumMax = sumTmp;
        }

        int operations = (sumMax * n * 2 - sumAll) / 2;
        
        std::cout << operations << '\n';
    }

    return 0;
}