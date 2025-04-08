#include <stdio.h>

int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N);

    if (N == 2)
        printf("1 1");
    else {
        int A[N], B[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &B[i][j]);
    
        int flag = N - 2;

        for (int i = 0; i < N; i++) {
            if (i < flag)
                A[i] = (B[i][i + 1] + B[i][i + 2] - B[i + 1][i + 2]) / 2;
            else if (i == flag)
                A[i] = (B[i][i + 1] + B[i][i - 1] - B[i + 1][i - 1]) / 2;
            else
                A[i] = (B[i][i - 1] + B[i][i - 2] - B[i - 1][i - 2]) / 2;

            printf("%d ", A[i]);
        }
    }
    return 0;
}