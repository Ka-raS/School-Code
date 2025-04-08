#include<stdio.h>
#include<stdbool.h>

bool isPalindrome_without9(int i)
{
    int iOriginal = i, iReversed = 0, remainder;
    while(i != 0)
    {
        remainder = i % 10;
        if(remainder == 9)
            return false;
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
    int N, numbers = 0;
    scanf("%d", &N);
    for(int i = 2; i < N; i++)
        if(isPalindrome_without9(i))
        {
            printf("%d ", i);
            numbers++;
        }
    printf("\n%d", numbers);
    return 0;
}