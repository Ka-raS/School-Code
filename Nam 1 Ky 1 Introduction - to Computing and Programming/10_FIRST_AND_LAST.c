#include<stdio.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);

    for(int i = 0; i < test_cases; i++)
    {   
        long long N, first_digit, last_digit;
        scanf("%lld", &N);
        last_digit = N % 10;
        while(N != 0)
        {
            first_digit = N % 10;
            N = N / 10;
        }

    if (first_digit == last_digit)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    }
    return 0;
}