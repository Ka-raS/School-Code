#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int n;
    while(1) {
        scanf("%d", &n);
        if(n == 0)
            break;

        scanf("\n");
        char s1[n + 1], s2[n + 1], s[2 * n + 1];
        scanf("%s%s%s", s1, s2, s);

        char s1Original[n], s2Original[n];
        strcpy(s1Original, s1);
        strcpy(s2Original, s2);

        int steps = 0;
        while(++steps) {
            char merge[2 * n + 1];
            int i, j = 0;
            for (i = 0; i < n; i++) {
                merge[j++] = s2[i];
                merge[j++] = s1[i];
            }
            merge[j] = '\0';
            if (strcmp(s, merge) == 0) {
                printf("%d\n", steps);
                break;
            }
            for (int i = 0; i < n; i++) {
                s1[i] = merge[i];
                s2[i] = merge[i + n];
            }
            if ((strcmp(s1, s1Original) == 0) && (strcmp(s1, s1Original) == 0)) {
                printf("-1\n");
                break;
            }
        }
    }
    return 0;
}