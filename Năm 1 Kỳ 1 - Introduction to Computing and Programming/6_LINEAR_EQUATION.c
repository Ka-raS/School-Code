#include<stdio.h>

int main(int argc, char* argv[]) {
    float a, b, x;
    scanf("%f%f", &a, &b);

    if(a == 0 && b == 0)
        printf("Infinite solutions");
    else if(a == 0)
        printf("No solution");
    else 
        printf("%.2f", - b / a);
    return 0;
}