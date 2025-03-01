#include <iostream>
#define max 200
using namespace std;

int findKthVal(int A[max][max], int N, int M, int k) {
    int i, j;
    int kth = 0;
    int fstRow = 0, fstCol = 0;
    int lasRow = N - 1, lasCol = M - 1;
    
    while(fstRow <= lasRow && fstCol <= lasCol) {
        for(j = fstCol; j <= lasCol; j++) {
            kth++;
            if (kth == k)
                return A[fstRow][j];
        }        
        fstRow++;
        for(i = fstRow; i <= lasRow; i++) {
            kth++;
            if (kth == k)
                return A[i][lasCol];
        }        
        lasCol--;
        if(fstRow <= lasRow) {
            for(j = lasCol; j >= fstCol; j--) {
                kth++;
                if (kth == k)
                    return A[lasRow][j];
            }        
            lasRow--;
        }
        if(fstCol <= lasCol) {
            for(i = lasRow; i >= fstRow; i--) {
                kth++;
                if (kth == k)
                    return A[i][fstCol];
            }        
            fstCol++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M, k;
        cin >> N >> M >> k;

        int A[max][max];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> A[i][j];
        
        int kthVal = findKthVal(A, N, M, k);
        cout << kthVal << endl;
    }
    return 0;
}