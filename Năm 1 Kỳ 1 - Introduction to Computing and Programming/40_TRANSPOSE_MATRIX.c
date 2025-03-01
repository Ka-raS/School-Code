#include<stdio.h>
#define max 99

void input_measurements(int *N_row, int *M_column)
{
    scanf("%d%d", &*N_row, &*M_column);
}

void input_array(int array[max][max], int N_row, int M_column)
{
    for(int i = 0; i < N_row; i++)
        for(int j = 0; j < M_column; j++)
            scanf("%d", &array[i][j]);
}

void output(int array[max][max], int M_row, int N_column)
{
    for(int i = 0; i < M_row; i++)
    {
        for(int j = 0; j < N_column; j++)
            printf("%d ", array[j][i]);
        printf("\n");
    }
}

int main(void)
{
    int array[max][max], N_row, M_column;
    input_measurements(&N_row, &M_column);
    input_array(array, N_row, M_column);
    output(array, M_column, N_row); 
    return 0;
}