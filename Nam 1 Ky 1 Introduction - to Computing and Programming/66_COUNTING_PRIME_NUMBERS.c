#include<stdio.h>
#include<stdbool.h>

bool isPrime(int i)
{
    if(i == 2)
        return true;
    if(i == 0 || i == 1 || i % 2 == 0)
        return false;
    for(int j = 3; j <= i/2; j += 2)
        if(i % j == 0)
            return false;
    return true;
}

bool hasAllPrime(int i)
{
    while(i != 0)
    {
        int digit = i % 10;
        if(isPrime(digit) == false)
            return false;
        i /= 10;
    }
    return true;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
    {
        int a, b, numbers = 0;
        scanf("%d%d", &a, &b);
        for(int i = a; i <= b; i++)
            if(hasAllPrime(i) && isPrime(i))
                numbers++;
        printf("%d\n", numbers);
    }
    return 0;
}