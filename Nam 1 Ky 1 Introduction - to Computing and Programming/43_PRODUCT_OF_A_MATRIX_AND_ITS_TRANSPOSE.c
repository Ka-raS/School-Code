#include<stdio.h>
#define max 100

void input(int array[max][max], int *m, int *n)
{
    scanf("%d%d", &*m, &*n);
    for(int y = 0; y < *m; y++)
        for(int x = 0; x < *n; x++)
            scanf("%d", &array[x][y]);
}

void transpose_matrix(int array[max][max], int transposed_array[max][max], int m, int n)
{
    for(int y = 0; y < m; y++)
        for(int x = 0; x < n; x++)
            transposed_array[y][x] = array[x][y];
}

void matrix_product(int array[max][max], int transposed_array[max][max], int result[max][max], int m, int n)
{
    for(int y = 0; y < m ; y++)
        for(int a = 0; a < m; a++)
            for(int x = 0; x < n; x++)
                result[a][y] += array[x][y] * transposed_array[a][x];
}

void output(int array[max][max], int columns, int rows, int test)
{
    printf("Test %d:\n", test);
    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < columns; x++)
            printf("%d ", array[x][y]);
        printf("\n");
    }
}

int main(void)
{
    int test_cases;
    scanf("%d", &test_cases);
    for(int test = 1; test <= test_cases; test++)
    {
        int array[max][max], transposed_array[max][max], result[max][max] = {0}, m, n;
        input(array ,&m, &n);
        transpose_matrix(array, transposed_array, m, n);
        matrix_product(array, transposed_array, result, m, n);
        output(result, m, m, test);
    }    
    return 0;
}