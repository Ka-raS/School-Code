#include<stdio.h>

int Prime_Number(long long N)
{
    long long dividend, remainder, result = 1;
    if ( N == 0 || N == 1 )
    {
        result = 0;
    }
    for (dividend = 2; dividend <= N/2; dividend++)
    {
        remainder = N % dividend;
        if (remainder == 0)
        {
            result = 0;
            break;
        }
    }
    if (result == 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
}

int main(void)
{
    long long test_cases, N;
    scanf("%lld", &test_cases);

    for(int i = 0; i < test_cases; i++)
    {
        scanf("%lld", &N);
        Prime_Number(N);
    }
    return 0;
}