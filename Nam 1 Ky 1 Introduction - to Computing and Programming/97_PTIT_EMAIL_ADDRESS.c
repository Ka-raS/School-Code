#include <stdio.h>
#include <string.h>
#define max 51

int main(int argc, char* argv[]) {
    char name[max];
    fgets(name, max, stdin);
    name[strlen(name) - 1] = '\0';
    
    char words[max][max];
    int length = 0;
    for (char* word = strtok(name, " "); word != NULL; word = strtok(NULL, " "))
        strcpy(words[length++], word);
    int i;
    for (i = 0; i < length - 1; i++) {
        if (words[i][0] < 91)
            words[i][0] += 32;
        printf("%c", words[i][0]);
    }
    length = strlen(words[i]);
    for (int j = 0; j < length; j++)
        if(words[i][j] < 91)
            words[i][j] += 32;
    printf("%s@ptit.edu.vn", words[i]);
    return 0;
}