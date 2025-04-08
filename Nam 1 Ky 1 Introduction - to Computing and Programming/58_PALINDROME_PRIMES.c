#include <stdio.h>
#include <stdbool.h>

bool isPrime(int i)
{
    if(i == 2)
        return true;
    if(i == 0 || i == 1 || i % 2 == 0)
        return false;
    for(int j = 3; j <= i / 2; j += 2)
        if(i % j == 0)
            return false;
    return true;
}

bool isPalindrome(int i)
{
    int iOriginal = i, iReversed = 0, remainder;
    while(i != 0)
    {
        remainder = i % 10;
        iReversed = iReversed * 10 + remainder;
        i /= 10;
    }
    if(iOriginal == iReversed)
        return true;
    else
        return false;
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        for(int i = a, numbers = 0; i <= b; i++)
            if(isPrime(i) && isPalindrome(i))
            {
                if(numbers == 10)
                {
                    printf("\n");
                    numbers = 0;
                }
                printf("%d ", i);
                ++numbers;
            }
        printf("\n\n");
    }
    return 0;
}