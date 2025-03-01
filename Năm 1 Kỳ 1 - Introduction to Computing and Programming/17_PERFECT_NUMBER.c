#include<stdio.h>

int main()
{
    long long sum = 1, i = 2, N_Temp, N;
    scanf("%lld", &N);
    N_Temp = N;
    for(i; i < N_Temp; i++)
        {
            if(N_Temp % i == 0)
                sum += i;
        }
    if(sum == N)
        printf("1");
    else
        printf("0");
    return 0;
}