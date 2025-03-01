#include <iostream>
using namespace std;

bool isMntSeq(int* A, int n, int i, int R) {
    if (R - i == 0)
        return true;
        
    if (R - i == 1) {
        if (A[i] < A[R])
            return true;
        else
            return false;
    }                

    while (A[i] == A[i + 1] && i < R)
        i++;
        
    if (A[i] > A[i + 1] || i == R)
        return false;
        
    while (A[i] <= A[i + 1] && i < R)
        i++;
        
    if (i == R)
        return false;
        
    while (A[i] >= A[i + 1] && i < R)
        i++;
    
    if (i == R)
        return true;    
        
    return false;            
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int n; 
        cin >> n;

        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
            
        int L, R;
        cin >> L >> R;
        
        if (isMntSeq(A, n, L, R))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}