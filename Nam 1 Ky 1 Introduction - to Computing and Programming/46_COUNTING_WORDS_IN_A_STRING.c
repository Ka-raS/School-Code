#include<stdio.h>
#include<ctype.h>
#define max 200

int words_counting(char string[max])
{
    int words = 0, i, flag = 1;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(isspace(string[i]))
            flag = 1;
        else
        {
            if(flag == 1)
                words++;
            flag = 0;
        }
    }
    return words;
}

int main(void)
{
    int test_cases, test;
    scanf("%d ", &test_cases);
    for(test = 0; test < test_cases; test++)
    {
        char string[max] = {};
        fgets(string, max, stdin);
        printf("%d\n", words_counting(string));
    }
    return 0;
}