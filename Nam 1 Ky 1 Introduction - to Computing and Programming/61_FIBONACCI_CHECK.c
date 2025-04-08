#include <stdio.h>
#include <stdbool.h>

int isFibonacci(long long n)
{
    long long a = 0, b = 1, c = a + b;
    if(n == a || n == b)
        return true;
    while(c <= n)
    {
        if(c == n)
            return true;
        a = b;
        b = c;
        c = a + b;
    }
    return false;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while(testCases--)
    {
        long long n;
        scanf("%lld", &n);
        if(isFibonacci(n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}