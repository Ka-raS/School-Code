//  Còn chưa học nhân ma trận, phải đọc công thức trên mạng 🗿

#include<stdio.h>
#define max 100

void input_measurements(int *n, int *m, int *p)
{
    scanf("%d%d%d", &*n, &*m, &*p);
}

void input_array(int array[max][max], int row, int column)
{
    for(int y = 0; y < row; y++)
        for(int x = 0; x < column; x++)
            scanf("%d", &array[x][y]);
}

void matrix_product(int A[max][max], int B[max][max], int result[max][max], int n, int m, int p)
{
    for(int y = 0; y < n ; y++)
        for(int a = 0; a < p; a++)
            for(int x = 0; x < m; x++)
                result[a][y] += A[x][y] * B[a][x];
}

void output(int array[max][max], int column, int row)
{
    for(int y = 0; y < row; y++)
    {
        for(int x = 0; x < column; x++)
            printf("%d ", array[x][y]);
        printf("\n");
    }
}

int main(void)
{
    int A[max][max], B[max][max], result[max][max], n, m, p, a;
    input_measurements(&n, &m, &p);
    input_array(A, n, m);
    input_array(B, m, p);
    matrix_product(A, B, result, n, m, p);
    output(result, p, n);
    return 0;
}