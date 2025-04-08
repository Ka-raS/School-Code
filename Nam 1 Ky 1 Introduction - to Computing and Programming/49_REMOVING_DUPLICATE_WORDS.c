#include<stdio.h>
#include<string.h>

#define max 100

void input(char string[max])
{
    fgets(string, max, stdin);
    string[strcspn(string, "\n")] = '\0';
}

void array(char string[max], char *string_array[max], int *string_array_index)
{
    for(char *string_word = strtok(string," "); string_word != NULL; string_word = strtok(NULL, " "), *string_array_index += 1)
        string_array[*string_array_index] = string_word;
}

void remove_duplicates(char string[max], char result[max], char *string_array[max], int string_array_length)
{
    char space = ' ';
    for(int i = 0; i < string_array_length; i++)
    {
        int flag = 0;
        for(int j = i + 1; j < string_array_length; j++)
            if(strcmp(string_array[i], string_array[j]) == 0)
                string_array[j] = "ReMoVe";
        if(string_array[i] != "ReMoVe")
        {
            strcat(result, string_array[i]);
            if(result[strlen(result) - 1] != '\n')
                strncat(result, &space, 1);
        }
    }
}

void output(char result[max])
{
    fputs(result, stdout);
}

int main(void)
{
    int string_array_index = 0;
    char string[max] = {}, result[max] = {}, *string_array[max] = {};
    input(string);
    array(string, string_array, &string_array_index);
    remove_duplicates(string, result, string_array, string_array_index);
    output(result);
    return 0;
}