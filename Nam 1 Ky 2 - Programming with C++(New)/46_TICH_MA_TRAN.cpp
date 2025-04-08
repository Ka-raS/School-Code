#include <bits/stdc++.h>

void inputMatrix(std::vector< std::vector<int> >& N, int rows, int cols) {
    int i, j;
    
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            std::cin >> N[i][j];
}

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    
    std::vector< std::vector<int> >
        A(n, std::vector<int>(m)),
        B(m, std::vector<int>(p));
    
    inputMatrix(A, n, m);
    inputMatrix(B, m, p);
    
    int i, j, k;
    long long sum;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            sum = 0;
            
            for (k = 0; k < m; k++)
                sum += A[i][k] * B[k][j];
                
            std::cout << sum << ' ';    
        }
        
        std::cout << '\n';
    }
            
    return 0;        
}