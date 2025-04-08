#include<stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i = 1, j = 1; j <= N; j++)
    {
        for(int k = 1; k <= j * 2; i++, k += 2)
        {
            if(j % 2 == 0)
                printf("%d ", i + j - k);
            else
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
