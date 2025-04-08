#include <stdio.h>
#include <math.h>

void swap(int *length, int *height) {
    int temp = *length;
    *length = *height;
    *height = temp;
}

int findSquareLen(int squareArea) {
    int squareLen = sqrt(squareArea);
	if(squareLen * squareLen == squareArea)
        return squareLen;
	return 0;
}

void swapRec(int rec, int a[3][2]) {
    for (int i = 0; i < 2; i++)
        swap(&a[0][i], &a[rec][i]);
}

int position1(int a[3][2], int squareLen) {
    for(int i = 0; i < 3; i++)
        if(a[i][0] != squareLen)
            return 0;
    return 1;
}

int position2(int a[3][2], int squareLen) {
    for(int i = 1; i < 3; i++)
        if (a[i][0] == squareLen)
            swapRec(i, a);
    if (a[0][0] == squareLen) {
        int gap = squareLen - a[0][1];
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                if(a[1][j] == gap && a[2][k] == gap)
                    return 1;
    }
    return 0;
}

int isSquare(int a[3][2], int squareArea) {
    int squareLen = findSquareLen(squareArea);
    if (squareLen == 0)
        return 0;
    if (position1(a, squareLen) || position2(a, squareLen))
        return 1;
    return 0;
}

int main(int argc, char* argv[]) {
    int a[3][2], squareArea = 0;

    for (int i = 0; i < 3; i++) {
        int recArea = 1;
        for (int j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
            recArea *= a[i][j];
        }
        squareArea += recArea;
        if (a[i][0] < a[i][1])
            swap(&a[i][0], &a[i][1]);
    }

    if (isSquare(a, squareArea))
        printf("YES");
    else
        printf("NO");
    return 0;
}