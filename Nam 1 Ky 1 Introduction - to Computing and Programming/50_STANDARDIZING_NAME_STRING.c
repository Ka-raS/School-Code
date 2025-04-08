#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define max 80

void standardizing(char string[max], char result[max])
{
    for(char *word = strtok(string," "); word != NULL; word = strtok(NULL, " "))
    {
        char temp[max] = {}, space = ' ';
        temp[0] = toupper(word[0]);
        for(int i = 1; i < strlen(word); i++)
            temp[i] = tolower(word[i]);
        strcat(result, temp);
        if(result[strlen(result) - 1] != '\n')
            strncat(result, &space, 1);
    }
}

int main(void)
{ 
    int test_cases;
    scanf("%d ", &test_cases);
    for(int test = 0; test < test_cases; test++)
    {
        char string[max] = {}, result[max] = {};
        fgets(string, max, stdin);
        standardizing(string, result);
        fputs(result, stdout);
    }
    return 0;
}