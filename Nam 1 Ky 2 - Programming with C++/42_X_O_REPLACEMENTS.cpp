#include<iostream>
#define SIZE 20
using namespace std;

typedef struct {
    bool val;
    bool isSurrounded;
} Arr;


void input(Arr A[SIZE][SIZE], int &N, int &M) {
    cin >> N >> M;

    char c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> c;

            A[i][j].isSurrounded = 1;
            if (c == 'O')
                A[i][j].val = 1;
            else 
                A[i][j].val = 0;
        }
}

void exclude(Arr A[SIZE][SIZE], int i, int j, int N, int M) {
    A[i][j].isSurrounded = 0;

    int above = i - 1, below = i + 1;
    int  left = j - 1, right = j + 1;

    if (above >= 0 && A[above][j].val && A[above][j].isSurrounded)
        exclude(A, above, j, N, M);

    if (below <  N && A[below][j].val && A[below][j].isSurrounded)
        exclude(A, below, j, N, M);

    if ( left >= 0 && A[i][ left].val && A[i][ left].isSurrounded)
        exclude(A, i, left, N, M);

    if (right <  M && A[i][right].val && A[i][right].isSurrounded)
        exclude(A, i, right, N, M);
}

void excludeBorders(Arr A[SIZE][SIZE], int N, int M) {
    int k;
    int rowMax = N - 1;
    int colMax = M - 1;

    for (k = 0; k < M; k++)
        if (A[0][k].val && A[0][k].isSurrounded)
            exclude(A, 0, k, N, M);

    for (k = 1; k < N; k++)
        if (A[k][0].val && A[k][0].isSurrounded)
            exclude(A, k, 0, N, M);

    for (k = 1; k < N; k++)
        if (A[k][colMax].val && A[k][colMax].isSurrounded)
            exclude(A, k, colMax, N, M);

    for (k = 1; k < colMax; k++)
        if (A[rowMax][k].val && A[rowMax][k].isSurrounded)
            exclude(A, rowMax, k, N, M);
}

void output(Arr A[SIZE][SIZE], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j].isSurrounded)
                cout << 'X' << " ";
            else
                cout << 'O' << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    Arr A[SIZE][SIZE];

    int T;
    cin >> T;

    while (T--) {
        input(A, N, M);
        excludeBorders(A, N, M);
        output(A, N, M);
    }
    return 0;
}