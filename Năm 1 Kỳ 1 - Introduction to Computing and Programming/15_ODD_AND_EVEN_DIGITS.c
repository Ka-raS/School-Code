#include<stdio.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    for(int i = 0; i < test_cases; i++)
    {
        long long N, digit, odd = 0, even = 0;
        scanf("%lld", &N);
        while(N != 0)
        {
            digit = N % 10;
            if (digit % 2 == 0)
                even++;
            else 
                odd++;
            N = N / 10;
        }
        printf("%lld %lld\n", odd, even);
    }
    return 0;
}