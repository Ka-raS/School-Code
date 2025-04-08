#include<stdio.h>

int main()
{
    int N, N_temp, digit, sum = 0, product = 1, digit_temp;
    scanf("%d", &N);
    N_temp = N;
    while(N_temp != 0)
    {
        digit = N_temp % 10;
        digit_temp = digit;
        for (digit_temp; digit_temp > 0; digit_temp--)
            product *= digit_temp;
        sum += product;
        N_temp /= 10;
        product = 1;
    }
    if (N == sum)
        printf("1");
    else 
        printf("0");
    return 0;
}