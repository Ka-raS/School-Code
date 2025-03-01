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

void input_swap_columns(int *swap_column_1, int *swap_column_2)
{
    scanf("%d%d", &*swap_column_1, &*swap_column_2);
}

void swap(int array[max][max], int column_1, int column_2, int N_row)
{

    for(int i = 0; i < N_row; i++)
    {
        int temp = array[i][column_1];
        array[i][column_1] = array[i][column_2];
        array[i][column_2] = temp;
    }
}

void output(int array[max][max], int N_row, int M_column)
{
    for(int i = 0; i < N_row; i++)
    {
        for(int j = 0; j < M_column; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int array[max][max], N_row, M_column, swap_column_1, swap_column_2;
    input_measurements(&N_row, &M_column);
    input_array(array, N_row, M_column);
    input_swap_columns(&swap_column_1, &swap_column_2);
    swap(array, swap_column_1 - 1, swap_column_2 - 1, N_row);
    output(array, N_row, M_column); 
    return 0;
}    