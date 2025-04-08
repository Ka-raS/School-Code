#include<stdio.h>
#define max 100

void spiral_matrix(int array[max][max], int N)
{
    int value = 1, i, x = 0, y = 0, last_column = N - 1, last_row = N - 1;
    while(x <= last_column && y <= last_row)
    {
        for(i = x; i <= last_column; i++, value++)
            array[y][i] = value;

        y++;
        for(i = y; i <= last_row; i++, value++)
            array[i][last_column] = value;

        last_column--;
        if(y <= last_row)
        {
            for(i = last_column; i >= x; i--, value++)
                array[last_row][i] = value;
            last_row--;
        }

        if(x <= last_column)
        {
            for(i = last_row; i >= y; i--, value++)
                array[i][x] = value;
            x++;
        }
    }
}

void output(int array[max][max], int N)
{
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
            printf("%d ", array[y][x]);
        printf("\n");
    }
}

int main(void)
{
    int array[max][max], N;
    scanf("%d", &N);
    spiral_matrix(array, N);
    output(array, N);
    return 0;
}