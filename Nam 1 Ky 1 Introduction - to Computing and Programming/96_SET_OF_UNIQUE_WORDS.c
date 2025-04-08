#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 101

int compareString(const void* a, const void* b) {
    char* x = (char*) a;
    char* y = (char*) b;
    return strcmp(x, y);
}

int main(int argc, char* argv[]) {
    char s1[max], s2[max];
    fgets(s1, max, stdin);
    fgets(s2, max, stdin);

    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;

    char *word, s1Words[max][max], s2Words[max][max];
    int s1Count = 0, s2Count = 0;

    for (word = strtok(s1, " "); word != NULL; word = strtok(NULL, " "))
        strcpy(s1Words[s1Count++], word);

    for (word = strtok(s2, " "); word != NULL; word = strtok(NULL, " "))
        strcpy(s2Words[s2Count++], word);

    qsort(s1Words, s1Count, sizeof(s1Words[0]), compareString);

    for (int i = 0; i < s1Count; i++) {
        while (!strcmp(s1Words[i], s1Words[i + 1]))
            i++;

        int flag = 1;
        for (int j = 0; j < s2Count; j++)
            if (!strcmp(s1Words[i], s2Words[j])) {
                flag = 0;
                break;
            }
        if (flag)
            printf("%s ", s1Words[i]);
    }

    return 0;
}