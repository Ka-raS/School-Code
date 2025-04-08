#include<bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    int i, j;
    int rows, cols;
    int lastRow, lastCol;
    int firstRow, firstCol;

    while (t--) {
        std::cin >> rows >> cols;

        int A[rows][cols];

        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                std::cin >> A[i][j];

        firstRow = 0;
        firstCol = 0;
        lastRow = rows - 1;
        lastCol = cols - 1;

        while (firstRow <= lastRow && firstCol <= lastCol) {
            for (j = firstCol; j <= lastCol; j++)
                std::cout << A[firstRow][j] << ' ';

            firstRow++;

            for (i = firstRow; i <= lastRow; i++)
                std::cout << A[i][lastCol] << ' ';

            lastCol--;

            if (firstRow <= lastRow) {
                for (j = lastCol; j >= firstCol; j--)
                    std::cout << A[lastRow][j] << ' ';

                lastRow--;
            }


            if (firstCol <= lastCol) {
                for (i = lastRow; i >= firstRow; i--)
                    std::cout << A[i][firstCol] << ' ';

                firstCol++;
            }
        }

        std::cout << '\n';
    }

    return 0;
}