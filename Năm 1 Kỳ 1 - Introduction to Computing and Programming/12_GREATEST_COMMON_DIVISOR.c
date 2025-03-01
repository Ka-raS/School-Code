#include<stdio.h>

long long N1, N2, test_cases, test, dividend;
int Greatest_Common_Divisor(long long N1, long long N2)
{
    for(dividend = N1; dividend >= 1; dividend--)
    {
        if ((N1 % dividend == 0) && (N2 % dividend == 0))
        {
            printf("%lld\n", dividend);
            break;
        }
        else{}
    }
}

int main(void)
{
    scanf("%lld", &test_cases);
    for(test = 0; test < test_cases; test++)
    {
        scanf("%lld %lld", &N1, &N2);
        Greatest_Common_Divisor(N1, N2);
    }
    return 0;
}