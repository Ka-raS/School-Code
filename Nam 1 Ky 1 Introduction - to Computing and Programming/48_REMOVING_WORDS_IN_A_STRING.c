#include<stdio.h>
#include<string.h>
#define max 100

void input(char string[max], char word[max])
{
    fgets(string, max, stdin);
    fgets(word, max, stdin);
    string[strcspn(string, "\n")] = '\0';
    word[strcspn(word, "\n")] = '\0';
}

void remove_word(char string[max], char word[max], char result[max])
{
    char space = ' ';
    for(char *string_word = strtok(string," "); string_word != NULL; string_word = strtok(NULL, " "))
    {
        if(strcmp(string_word, word) != 0)
        {
            strcat(result, string_word);
            strncat(result, &space, 1);
            string[strcspn(string, "\n")] = '\0';
        }
    }
}

void output(char result[max])
{
    fputs(result, stdout);
}

int main(void)
{
    char string[max] = {}, word[max] = {}, result[max] = {};
    input(string, word);
    remove_word(string, word, result);
    output(result);
    return 0;
}