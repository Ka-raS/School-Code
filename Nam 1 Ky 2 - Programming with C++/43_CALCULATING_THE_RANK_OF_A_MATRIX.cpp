// C++ program to find rank of a matrix
#include <bits/stdc++.h>
#define SIZE 15
using namespace std;

void input(int A[SIZE][SIZE], int& N, int& M) {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
}

/* function for exchanging two rows of
a matrix */
void swap(int A[SIZE][SIZE], int row1, int row2, int col) {
	for (int i = 0; i < col; i++) {
		int temp = A[row1][i];

		A[row1][i] = A[row2][i];
		A[row2][i] = temp;
	}
}

void display(int A[SIZE][SIZE], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

/* function for finding rank of matrix */
int rankOfMatrix(int A[SIZE][SIZE], int N, int M) {
	int i;
	int rank = N;

	for (int row = 0; row < rank; row++) {
		// Before we visit current row 'row', we make
		// sure that mat[row][0],....mat[row][row-1]
		// are 0.

		// Diagonal element is not zero
		if (A[row][row]) {
			for (int col = 0; col < M; col++)

				if (col != row) {
					// This makes all entries of current
					// column as 0 except entry 'mat[row][row]'

					double mult = (double)A[col][row] / (double)A[row][row];

					for (i = 0; i < rank; i++)
						A[col][i] -= mult * A[row][i];
				}
		}

		// Diagonal element is already zero. Two cases
		// arise:
		// 1) If there is a row below it with non-zero
		// entry, then swap this row with that row
		// and process that row
		// 2) If all elements in current column below
		// mat[r][row] are 0, then remove this column
		// by swapping it with last column and
		// reducing number of columns by 1.
		else {
			bool reduce = true;

			for (i = row + 1; i < N; i++) {
				// Swap the row with non-zero element
				// with this row.
				if (A[i][row]) {
					swap(A, row, i, rank);

					reduce = false;
					break;
				}
			}

			// If we did not find any row with non-zero
			// element in current column, then all
			// values in this column are 0.
			if (reduce) {
				// Reduce number of columns
				rank--;

				// Copy the last column here
				for (i = 0; i < N; i ++)
					A[i][row] = A[i][rank];
			}

			// Process this row again
			row--;
		}
	}
	// Uncomment these lines to see intermediate results

	display(A, N, M);
	cout << endl;

	return rank;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int A[SIZE][SIZE];

	int T;
	cin >> T;

	while (T--) {
		input(A, N, M);
		cout << rankOfMatrix(A, N, M) << endl;
	}

	return 0;
}
