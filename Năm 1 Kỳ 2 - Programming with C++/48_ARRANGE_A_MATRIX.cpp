#include <iostream>
#include <cstdlib>
using namespace std;

int ascending(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols, col;
    cin >> rows >> cols >> col;

    // int len = max(rows, cols);
    int A[cols][rows];
    int i, j;

    for (j = 0; j < rows; j++)
        for (i = 0; i < cols; i++)
            cin >> A[i][j];

    qsort(A[col - 1], rows, sizeof(int), ascending);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            cout << A[j][i] << " ";
        cout << endl;
    }

    return 0;
}