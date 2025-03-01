#include<stdio.h>

int main()
{
    long long a, b, sum = 0, i, N1, N2;
    scanf("%lld %lld", &N1, &N2);
    if(N1 < N2)
    {
        a = N1;
        b = N2;
    }
    else
    {
        a = N2;
        b = N1;
    }
    for(i = a; i <= b; i++)
    {
        sum += i;
    }
    printf("%lld", sum);
    return 0;
}