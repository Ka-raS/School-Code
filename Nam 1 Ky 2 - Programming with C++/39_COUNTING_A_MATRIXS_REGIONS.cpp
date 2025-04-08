#include<iostream>
#define max 200
using namespace std;

void findConnected(int A[max][max], int i, int j) {
    A[i][j] = 0;

    for (int a = i - 1; a < i + 2; a++)
        for (int b = j - 1; b < j + 2; b++)
            if (A[a][b])
                findConnected(A, a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        int A[max][max];
        int regions = 0;
        int i, j;

        for (i = 1; i <= N; i++)
            for (j = 1; j <= M; j++)
                cin >> A[i][j];
                
        for (i = 1; i <= N; i++)
            for (j = 1; j <= M; j++)
                if (A[i][j]) {
                    regions++;
                    findConnected(A, i, j);
                }
                
        cout << regions << endl;
    }

    return 0;
}