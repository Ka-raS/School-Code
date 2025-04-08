#include<stdio.h>
#define max 500

int isPrettyNumber(char number[])
{
    int length = 0, sum = 0;
    while(number[length] != '\n')
    {
        sum += number[length] - 48;
        length++;
    }
    if(number[length - 1] != '8' || sum % 10 != 0)
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