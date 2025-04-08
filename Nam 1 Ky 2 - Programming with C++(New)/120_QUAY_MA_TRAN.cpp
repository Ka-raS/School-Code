#include<bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int i, j, tmp;
    int rows, cols;
    int lastRow, lastCol;

    while (t--) {
        std::cin >> rows >> cols;

        int A[rows][cols];
        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                std::cin >> A[i][j];

        lastRow = 0;
        lastCol = 0;

        while (lastRow < rows / 2 || lastCol < cols / 2) {
            tmp = A[rows - lastRow - 1][cols - lastCol - 1];
            i = rows - lastRow - 1;
            j = cols - lastCol - 1;


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

        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                std::cout << A[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}