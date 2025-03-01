#include<stdio.h>
#include<stdbool.h>

bool isSpeciallyEven(long long N)
{
    while(N != 0)
    {
        long long digit = N % 10;
        if(digit % 2 != 0)
            return false;
        N /= 10;
    }
    return true;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
    {
        long long N;
        scanf("%lld", &N);
        if(isSpeciallyEven(N))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}