#include<stdio.h>
#include<math.h>

int isLuckyNumber(long long i)
{
    int sumDigits = 0;
    long long iOriginal = i, iReversed = 0;
    while(i != 0)
    {
        int digit = i % 10;
        if(digit == 4)
            return 0;
        iReversed = iReversed * 10 + digit;
        sumDigits += digit;
        i /= 10;
    }
    if(iOriginal != iReversed || sumDigits % 10 != 0)
        return 0;
    return 1;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
    {
        int N;
        scanf("%d", &N);
        for(long long i = pow(10, N - 1) + 1; i < pow(10, N); i++)
            if(isLuckyNumber(i))
                printf("%lld ", i);
        printf("\n");
    }
    return 0;
}