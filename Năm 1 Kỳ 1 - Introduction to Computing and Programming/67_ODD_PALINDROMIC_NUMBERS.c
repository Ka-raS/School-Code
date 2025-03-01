#include <stdio.h>
#include <stdbool.h>

bool hasEvenDigit_or_hasEvenSumDigits(long long N)
{
    int sum = 0;
    while(N != 0)
    {
        int digit = N % 10;
        if(digit % 2 == 0)
            return true;
        sum += digit;
        N /= 10;
    }
    if(sum % 2 == 0)
        return true;
    return false;
}

bool isNotPalindromic(long long N)
{
    long long originalN = N, reversedN = 0;
    for(N; N != 0; N /= 10)
        reversedN = reversedN * 10 + (N % 10);
    if(originalN != reversedN)
        return true;
    else
        return false;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
    {
        long long N;
        scanf("%lld", &N);
        if(hasEvenDigit_or_hasEvenSumDigits(N) || isNotPalindromic(N))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}