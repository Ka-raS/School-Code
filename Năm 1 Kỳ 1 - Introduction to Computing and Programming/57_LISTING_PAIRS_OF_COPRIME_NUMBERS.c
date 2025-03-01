#include<stdio.h>

int haveCommonDivisor(int i, int j)
{
    for(int k = i; k > 1; k--)
        if(i % k == 0 && j % k == 0)
            return 0;
    return 1;        
}

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i = a; i < b; i++)
        for(int j = i + 1; j <= b; j++)
            if(haveCommonDivisor(i, j))
                printf("(%d,%d)\n", i, j);
    return 0;
}