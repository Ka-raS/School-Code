#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int A[N][N];
        
        int sumMax = 0;
        int sumAll = 0;
        int sumTmp = 0;
        
        int i, j;
        
        for (i = 0; i < N; i++) {
            sumTmp = 0;
            
            for (j = 0; j < N; j++) {
                cin >> A[i][j];
                sumTmp += A[i][j];
            }
            sumAll += sumTmp;
            
            if (sumMax < sumTmp)
                sumMax = sumTmp;
            
        }
        for (j = 0; j < N; j++) {
            sumTmp = 0;
            
            for (i = 0; i < N; i++)
                sumTmp += A[i][j];
                
            sumAll += sumTmp;    
                
            if (sumMax < sumTmp)
                sumMax = sumTmp;
        }
        int operations = (sumMax * N * 2 - sumAll) / 2;
        
        cout << operations << endl;
    }

    return 0;
}