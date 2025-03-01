#include<stdio.h>

int Greatest_Common_Divisor(long long a, long long b)
{
    while (a != b)
    {
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    printf("%lld\n", a);
}
int main(void)
{
    long long test_cases, test, a, b;
    scanf("%lld", &test_cases);
    for(test = 0; test < test_cases; test++)
    {
        scanf("%lld %lld", &a, &b);
        Greatest_Common_Divisor(a, b);
    }
    return 0;
}