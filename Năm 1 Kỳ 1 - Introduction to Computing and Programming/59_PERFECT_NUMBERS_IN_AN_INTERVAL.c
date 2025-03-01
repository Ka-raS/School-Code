#include <stdio.h>

void sort(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int divisorsSum(int i)
{
    int sum = 0;
    for(int j = 1; j < i; j++)
        if(i % j == 0)
            sum += j;
    return sum;
}

void printPerfectNumbers(int a, int b)
{
    for(int i = a; i <= b; i++)
        if(divisorsSum(i) == i)
            printf("%d ", i);
}

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    if(a > b)
        sort(&a, &b);
    printPerfectNumbers(a, b);
    return 0;
}