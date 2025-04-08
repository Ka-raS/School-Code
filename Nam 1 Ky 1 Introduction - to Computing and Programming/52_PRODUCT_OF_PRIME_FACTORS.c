#include<stdio.h>

long long result(long long number)
{
    long long i = 2, j = 0, product = 1;
    while(i <= number)
    {
        if(number % i == 0)
        {
            if(j != i)
            {
                j = i;
                product *= i;
            }
            number = number / i;
            i = 2;
        }
        else
            i++;
    }
    return product;
}

int main(void)
{
    int test_cases;
    scanf("%d", &test_cases);
    for(int test = 0; test < test_cases; test++)
    {
        long long number = 0;
        scanf("%lld", &number);
        printf("%lld\n", result(number));
    }
    return 0;
}