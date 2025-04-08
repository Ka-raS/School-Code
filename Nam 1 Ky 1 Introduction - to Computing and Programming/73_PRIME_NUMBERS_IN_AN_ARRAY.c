#include<stdio.h>

int isPrime(int i)
{
    if(i == 2)
        return 1;
    if(i == 0 || i == 1 || i % 2 == 0)
        return 0;
    for(int j = 3; j <= i/2; j += 2)
        if(i % j == 0)
            return 0;
    return 1;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while(testCases--)
    {
        int N;
        scanf("%d", &N);
        for(int i = 0, j; i < N; i++)
        {
            scanf("%d", &j);
            if(isPrime(j))
                printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}