#include <stdio.h>
#define max 20

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char* argv[]) {
    int rows, columns, matrix[max][max], rowA, rowB;

    scanf("%d%d", &rows, &columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            scanf("%d", &matrix[i][j]);
    scanf("%d%d", &rowA, &rowB);
    
    for (int i = 0; i < columns; i++)
        swap(&matrix[rowA - 1][i], &matrix[rowB - 1][i]);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}