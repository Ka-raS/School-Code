#include <iostream>

int main()
{
    int n; // matrix size
    std::cin >> n;
    int A[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> A[i][j]; // input matrix

    int X[n][n];       // sums of sub matrixes' main diagonals
    int Y[n][n];       // sums of sub matrixes' secondary diagonals
    int ans = A[0][0]; // answer

    for (int i = 0; i < n; ++i)     // i: row
        for (int j = 0; j < n; ++j) // j: column
        {
            X[i][j] = Y[i][j] = A[i][j];  // copy from matrix A into matrix X and Y
            ans = std::max(ans, A[i][j]); // check sub array size 1
        }

    for (int k = 1; k < n; ++k)             // k: sub matrix size
        for (int i = 0; i < n - k; ++i)     // i: row
            for (int j = 0; j < n - k; ++j) // j: column
            {
                X[i][j] = A[i][j] + X[i + 1][j + 1]; // sum of the main diagonal from the sub matrix size k+1,
                                                     // starting row index = i, starting column index = j

                Y[i][j + k] = A[i][j + k] + Y[i + 1][j + k - 1]; // sum of the secondary diagonal from the sub matrix size k+1,
                                                                 // starting row index = i, starting column index = j+k

                ans = std::max(ans, X[i][j] - Y[i][j + k]); // value = main diagonal - secondary diagonal
            }

    std::cout << ans;
}