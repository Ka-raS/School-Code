#include<stdio.h>
#define max 31623

void square_numbers(long long m, long long n)
{
    int k = 0;
    long long array[max] = {};
    for(int i = 0; i * i <= n; i++)
        if(i * i >= m && i * i <= n)
        {
            array[k] = i * i;
            k++;
        }
    printf("%d\n", k);
    for(int i = 0; i < k; i++)
        printf("%lld\n", array[i]);
}

int main(void)
{
    long long m, n;
    scanf("%lld%lld", &m, &n);
    square_numbers(m, n);
    return 0;
}