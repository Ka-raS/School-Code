#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int frequency;
    int index;
} Array;

int compareFrequency(const void *x, const void *y) {
    Array *a = (Array *)x;
    Array *b = (Array *)y;
    if (a->frequency == b->frequency)
        return a->index < b->index;
    return a->frequency > b->frequency;
}

int compareValue(const void *x, const void *y) {
    Array *a = (Array *)x;
    Array *b = (Array *)y;
    if(a->value == b->value)
        return a->index - b->index;
    return a->value - b->value;
}
int main(int argc, char* argv[]) {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int N;
        scanf("%d", &N);

        int ansLen = 0;
        Array *ans = (Array *)malloc(N * sizeof(*ans));
        Array *A = (Array *)malloc(N * sizeof(*A));

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i].value);
            A[i].index = i;
        }
        qsort(A, N, sizeof(*A), compareValue);

        for (int i = 0; i < N; i++) {
            if (A[i].value == A[i + 1].value) {
                ans[ansLen].frequency = 1;
                ans[ansLen].index = A[i].index;

                while (A[i].value == A[i + 1].value) {
                    ans[ansLen].value = A[i++].value;
                    ans[ansLen].frequency++;
                }
                ansLen++;
            }
            else {
                ans[ansLen].frequency = 1;
                ans[ansLen].index = A[i].index;
                ans[ansLen].value = A[i].value;
                ansLen++;
            }
        }
        qsort(ans, ansLen, sizeof(*ans), compareFrequency);

        for (int i = ansLen; i >= 0; i--)
            for (int j = 0; j < ans[i].frequency; j++)
                printf("%d ", ans[i].value);

        printf("\n");
    }
    return 0;
}