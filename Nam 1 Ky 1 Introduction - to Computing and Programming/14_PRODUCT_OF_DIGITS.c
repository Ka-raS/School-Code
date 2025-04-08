#include<stdio.h>

int main()
{
    long long N, result = 1, digit;
    scanf("%lld", &N);
    while(N != 0)
    {
        digit = N % 10;
        result *= digit;
        N = N / 10;
    }
    printf("%lld", result);
    return 0;
}