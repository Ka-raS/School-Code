#include<stdio.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    for(int i = 0; i < test_cases; i++)
    {
        long long N, result = 0, digit;
        scanf("%lld", &N);
        while(N != 0)
        {
            digit = N % 10;
            result += digit;
            N = N / 10;
        }
        if (result % 10 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}