#include <stdio.h>

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while(testCases--)
    {
        long long N, i = 3;
        scanf("%lld", &N);
        while(N % 2 == 0)
            N /= 2;
        while(i * i <= N)
        {
            if(N % i == 0)
                N /= i;
            else
                i += 2;
        }
        printf("%lld\n", N);
    }
    return 0;
}