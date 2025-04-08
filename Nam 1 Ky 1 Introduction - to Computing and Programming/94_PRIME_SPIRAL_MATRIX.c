#include <stdio.h>
#define max 20

int isPrime(int i) {
    for (int j = 3; j * j <= i; j += 2)
        if (i % j == 0)
            return 0;
    return 1;
}

int nextPrime(int i) {
    if (i == 2)
        return 3;
    while (i += 2)
        if (isPrime(i))
            return i;
}

void findSpiralMatrix(int A[max][max], int length) {
    int value = 2, x = 0, y = 0, lastColumn = length - 1, lastRow = length - 1, i;

    while (x <= lastColumn && y <= lastRow) {
        for (i = x; i <= lastColumn; i++) {
            A[y][i] = value;
            value = nextPrime(value);
        }
        y++;

        for (i = y; i <= lastRow; i++) {
            A[i][lastColumn] = value;
            value = nextPrime(value);
        }
        lastColumn--;

        if (y <= lastRow) {
            for (i = lastColumn; i >= x; i--) {
                A[lastRow][i] = value;
                value = nextPrime(value);
            }
            lastRow--;
        }
           if (x <= lastColumn) {
            for(i = lastRow; i >= y; i--) {
                A[i][x] = value;
                value = nextPrime(value);
            }
            x++;
        }
    }
}

int main(int argc, char* argv[]) {
    int testCases;
    scanf("%d", &testCases);

    for (int test = 1; test <= testCases; test++) {
        int length, A[max][max] = {0};
        scanf("%d", &length);

        findSpiralMatrix(A, length);

        printf("Test %d:\n", test);
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++)
                printf("%d ", A[i][j]);
            printf("\n");
        }
    }
    return 0;
}