#include <stdio.h>

int hasMoreOddDigits(long long N)
{
    int evenDigits = 0, oddDigits = 0;
    for(N; N != 0; N /= 10)
    {
        if((N % 10) % 2 == 0)
            evenDigits++;
        else
            oddDigits++;
    }
    if(evenDigits <= oddDigits)
        return 1;
    else
        return 0;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
    {
        long long N;
        scanf("%lld", &N);
        if(N % 2 != 0 || hasMoreOddDigits(N))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}