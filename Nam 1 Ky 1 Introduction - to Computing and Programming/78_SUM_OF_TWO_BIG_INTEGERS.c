#include<stdio.h>
#include<string.h>
#define max 500

void convertArray(char* n, int nArray[])
{
    int nLen = strlen(n);
    for(int i = 0; i < nLen; i++)
        nArray[i] = n[nLen - i - 1] - 48;
}

void printSum(char* a, char* b)
{
    int aLen = strlen(a), aArray[max] = {0}, bArray[max] = {0}, digit, remainder = 0, i;
    convertArray(a, aArray);
    convertArray(b, bArray);
    for(i = 0; i < aLen; i++)
    {
        digit = aArray[i] + bArray[i] + remainder;
        remainder = digit / 10;
        aArray[i] = digit % 10;
    }
    if(remainder)
        aArray[i++] = remainder;
    while(i--)
        printf("%d", aArray[i]);
    printf("\n");
}

int main(int argc, char* argv[])
{
    int testCases;
    scanf("%d", &testCases);
    while(testCases--)
    {
        char a[max], b[max];
        scanf("%s%s", a, b);
        if(strlen(a) > strlen(b))
            printSum(a, b);
        else
            printSum(b, a);
    }
    return 0;
}