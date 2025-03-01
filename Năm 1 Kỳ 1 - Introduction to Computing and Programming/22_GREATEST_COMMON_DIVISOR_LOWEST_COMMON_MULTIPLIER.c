#include<stdio.h>

int greatest_common_divisor(long a, long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a > b)
        return greatest_common_divisor(a % b, b);
    else 
        return greatest_common_divisor(a, b % a);
}

long long lowest_common_multiplier(long a, long b, long i)
{
    if (i == 0)
        return 0;
    else 
        return a * b / i;
}

int main(void)
{
    long a, b;
    scanf("%ld%ld", &a, &b);
    long i = greatest_common_divisor(a, b);
    printf("%ld\n", i);
    printf("%lld\n", lowest_common_multiplier(a, b, i));
    return 0;
}