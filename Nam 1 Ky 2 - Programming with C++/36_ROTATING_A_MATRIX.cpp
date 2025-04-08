#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int rows, cols;
        cin >> rows >> cols;

        int A[rows][cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> A[i][j];

        int lastRow = 0;
        int lastCol = 0;

        while (lastRow < rows / 2 || lastCol < cols / 2) {
            int tmp = A[rows - lastRow - 1][cols - lastCol - 1];
            int i = rows - lastRow - 1;
            int j = cols - lastCol - 1;


            while (i > lastRow) {
                A[i][j] = A[i - 1][j];
                i--;
            }
            while (j > lastCol) {
                A[i][j] = A[i][j - 1];
                j--;
            }
            while (i < rows - lastRow - 1) {
                A[i][j] = A[i + 1][j];
                i++;
            }
            while (j < cols - lastCol - 2) {
                A[i][j] = A[i][j + 1];
                j++;
            }
            A[i][j] = tmp;
            lastRow++;
            lastCol++;
        }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cout << A[i][j] << " ";
    }

    return 0;
}