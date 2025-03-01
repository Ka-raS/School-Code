#include<stdio.h>
#define max 100

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    for(int test = 1; test <= testCases; test++)
    {
        printf("Test %d:\n", test);
        int N, A[max][max] = {0};
        scanf("%d", &N);
        for(int j = 0; j < N; j++)
            for(int i = 0; i <= j; i++)
                A[j][i] = i + 1;
        for(int k = 0; k < N; k++)
        {
            for(int j = 0; j < N; j++)
            {
                int sum = 0;
                for(int i = 0; i < N; i++)
                    sum += A[k][i] * A[j][i];
                printf("%d ", sum);
            }
            printf("\n");
        }
    }
    return 0;
}