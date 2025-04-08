#include<stdio.h>

void sort(int *m, int *n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}

int greatestCommonDivisor(int m, int n)
{
    if(m > n)
        sort(&m, &n);
    if(n % m == 0)
        return m;
    for(int i = m / 2; i != 0; i--)
        if(m % i == 0 && n % i == 0)
            return i;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while(testCases--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(greatestCommonDivisor(a, b) == greatestCommonDivisor(c, d))
            printf("YES\n");
        else
            printf("NO\n");
    }       
    return 0;
}