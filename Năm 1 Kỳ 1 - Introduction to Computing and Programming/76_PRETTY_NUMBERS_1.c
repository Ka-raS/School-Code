#include<stdio.h>
#define max 500

int isPrettyNumber(char number[])
{
    int length = 0;
    for(length; number[length] != '\n'; length++)
        if(number[length] % 2 != 0)
            return 0;
    for(int i = 0; number[i] != '\n'; i++)
        if(number[i] != number[length - i - 1])
            return 0;
    return 1;
}

int main(void)
{
    int testCases;
    scanf("%d\n", &testCases);
    while(testCases--)
    {
        char number[max] = {};
        fgets(number, max, stdin);
        if(isPrettyNumber(number) == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}