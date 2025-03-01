#include<stdio.h>
#define max 1000

void input(int array[max][3], int *N)
{
    scanf("%d", &*N);
    for(int y = 0; y < *N; y++)
        for(int x = 0; x < 3; x++)
            scanf("%d", &array[y][x]);
}

void binary_matrix(int array[max][3], int N, int *satisfied_rows)
{
    for(int y = 0; y < N; y++)
    {
        int ones = 0;
        for(int x = 0; x < 3; x++)
        {
            if(array[y][x] == 1)
                ones++;
            if(ones == 2)
                break;
        }
        if(ones > 1)
            *satisfied_rows = *satisfied_rows + 1;
    }  
}

int main(void)
{
    int N, satisfied_rows = 0, array[max][3];
    input(array, &N);
    binary_matrix(array, N, &satisfied_rows);
    printf("%d", satisfied_rows);
    return 0;
}