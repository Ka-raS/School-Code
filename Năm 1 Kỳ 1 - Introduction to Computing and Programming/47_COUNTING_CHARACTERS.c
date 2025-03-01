#include<stdio.h>
#include<ctype.h>
#define max 200

void counting_characters(char string[max])
{
    int i, letters = 0, digits = 0, others = 0;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(isalpha(string[i]))
            letters++;
        else if(isdigit(string[i]))
            digits++;
        else
            others++;
    }
    printf("%d %d %d", letters, digits, others - 1);
}

int main(void)
{
    char string[max] = {};
    fgets(string, max, stdin);
    counting_characters(string);
    return 0;
}