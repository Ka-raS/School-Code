#include<stdio.h>
#define max 100000

int main(int argc, char* argv[]) {
    int testCases;
    scanf("%d", &testCases);

    for (int test = 1; test <= testCases; test++) {
        int a[max] = {0}, count[max] = {0}, length;

        scanf("%d", &length);
        for (int i = 0; i < length; i++) {
            scanf("%d", &a[i]);
            count[a[i]]++;
        }

        printf("Test %d:\n", test);
        for (int i = 0; i < length; i++)
            if (count[a[i]]) {
                printf("%d appears %d times\n", a[i], count[a[i]]);
                count[a[i]] = 0;
            }
    }

    return 0;
}
