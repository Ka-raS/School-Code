#include<stdio.h>
#define max 100

int main(int argc, char* argv[]) {
    int testCases;
    scanf("%d", &testCases);

    for (int test = 1; test <= testCases; test++) {
        int N, length = 0, a[max] = {0}, b[max] = {0}, count = 0;

        scanf("%d", &N);
        for (int i = 0, temp = 0, j = 0; i < N; i++) {
            scanf("%d", &a[i]);
            if (a[i] > temp) {
                j++;
                if (j >= length)
                    length = j;
            }
            else
                j = 1;
            temp = a[i];
        }

        for (int i = 1, j = 0, k = 1; i < N; i++) {
            if (a[i] > a[i - 1]) {
                k++;
                if (k == length) {
                    b[j] = i;
                    j++;
                    count++;
                }
            }
            else
                k = 1;
        }

        printf("Test %d:\n", test);
        printf("%d\n", length);
        for (int i = 0; i < count; i++) {
            for (int j = 1; j <= length; j++)
                printf("%d ", a[b[i] - length + j]);
            printf("\n");
        }

    }

    return 0;
}