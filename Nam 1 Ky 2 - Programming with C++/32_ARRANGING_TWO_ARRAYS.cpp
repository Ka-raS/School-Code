#include <iostream>
#include <cstdlib>
using namespace std;

int asc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int n, m; 
        cin >> n >> m;

        int A[n], B[m];
        int freA[n] = {0};
        int freB[100000] = {0};
        
        for (int i = 0; i < n; i++)
            cin >> A[i];
            
        qsort(A, n, sizeof(int), asc);    
            
        for (int i = 0; i < m; i++) {
            cin >> B[i];
            freB[B[i]]++;
            
            if (freB[B[i]] == 1) {
                int j = 0;
            
                while (A[j] < B[i])
                    j++;
            
                while (A[j] == B[i]) {
                    cout << A[j] << " ";
                    freA[j]++;
                    j++;
                }
            }       
        }    
        
        for (int i = 0; i < n; i++)
            if (freA[i] == 0)
                cout << A[i] << " ";
        cout << endl;
    }

    return 0;
}