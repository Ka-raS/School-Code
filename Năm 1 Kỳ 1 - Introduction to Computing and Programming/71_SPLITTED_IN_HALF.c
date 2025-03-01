#include<stdio.h>
#define invalid -1

int splittedDigitValue[10] = {0, 1, invalid, invalid, invalid, invalid, invalid, invalid, 0, 0};

long long powerOf10(int i)
{
    if(i == 0)
        return 1;
    return 10 * powerOf10(i - 1);
}

long long splittedNumberValue(long long N)
{
    long long result = 0;
    for(int i = 1; N != 0; N /= 10, i++)
    {
        int digit = N % 10;
        int splittedDigit = splittedDigitValue[digit];
        if(splittedDigit == -1)
            return invalid;
        result += powerOf10(i - 1) * splittedDigit;
    }
    return result;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while(testCases--)
    {
        long long N;
        scanf("%lld", &N);
        long long result = splittedNumberValue(N);
        if(result == invalid || result == 0)
            printf("INVALID\n");
        else
            printf("%lld\n", result);
    }
    return 0;
}