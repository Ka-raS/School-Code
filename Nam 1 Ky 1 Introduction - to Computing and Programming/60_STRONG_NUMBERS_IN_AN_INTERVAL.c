#include <stdio.h>
#include <stdbool.h>

void sort(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n)
{
    if(n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}

bool isStrongNumbers(int i)
{
    int iOriginal = i, remainder, sumFactorial = 0;
    while(i != 0)
    {
        remainder = i % 10;
        sumFactorial += factorial(remainder);
        i /= 10;
    }
    if(iOriginal == sumFactorial)
        return true;
    else
        return false;    
}

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    if(a > b)
        sort(&a, &b);
    for(int i = a; i <= b; i++)
        if(isStrongNumbers(i))
            printf("%d ", i);
    return 0;
}