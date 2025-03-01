#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool isNonDecreasing(int i)
{
    while(i != 0)
    {
        int digitRight = i % 10;
        i /= 10;
        int digitLeft = i % 10;
        if(digitLeft > digitRight)
            return false;
    }
    return true;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
    {
        int N;
        scanf("%d", &N);
        for(int i = pow(10, N - 1) + 1; i < pow(10, N); i++)
            if(isNonDecreasing(i))
                printf("%d ", i);
        printf("\n");
    }
    return 0;
}