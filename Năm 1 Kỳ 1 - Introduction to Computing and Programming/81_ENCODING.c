#include <stdio.h>

int main(void) {
    int TestCases;
    scanf("%d\n", &TestCases);

    while(TestCases--) {
        char string[100];
        fgets(string, 100, stdin);

        for(int i = 0, AdjacentCharacters = 1; string[i] != '\n'; i++) {
            if(string[i] == string[i + 1])
                AdjacentCharacters++;
            else {
                printf("%c%d", string[i], AdjacentCharacters);
                AdjacentCharacters = 1;
            }
        }
        printf("\n");
    }
    return 0;
}