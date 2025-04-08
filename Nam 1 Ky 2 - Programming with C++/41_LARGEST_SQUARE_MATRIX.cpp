#include <iostream>
#define SIZE 20
using namespace std;

void input(bool A[SIZE][SIZE], int N)
{
    char c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> c;
            if (c == 'X')
                A[i][j] = 0;
            else
                A[i][j] = 1;
        }
}

int findMatrixLen(bool A[SIZE][SIZE], int N, int i, int j)
{
    int k;
    int len = 1;
    int rowMax = len + i;
    int colMax = len + j;
    int lenMax = min(N - i, N - j);

    while (len <= lenMax)
    {
        for (k = i; k < rowMax; k++)
            if (A[k][colMax])
                return len;

        for (k = j; k <= colMax; k++)
            if (A[rowMax][k])
                return len;

        len++;
        rowMax++;
        colMax++;
    }
    return lenMax;
}

int findLargestSquareMatrix(bool A[SIZE][SIZE], int N)
{
    int lenMax = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (A[i][j] == 0)
            {
                int len = findMatrixLen(A, N, i, j);
                if (lenMax < len)
                {
                    if (len == N - i)
                        return N - i;
                    lenMax = len;
                }
            }
    return lenMax;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int N;
    bool A[SIZE][SIZE];

    while (T--)
    {
        cin >> N;
        input(A, N);

        int len = findLargestSquareMatrix(A, N);
        cout << len << endl;
    }
    return 0;
}