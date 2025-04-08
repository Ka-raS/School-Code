#include<stdio.h>
// FIRST TRY 0 BUG LMAO
int main(int argc, char* argv[]) {
    float a, b, c, delta, x1, x2, i;
    scanf ("%f%f%f", &a, &b, &c);
    delta = b * b - 4 * a * c;
    x1 = (- b + sqrt(delta)) / (2 * a);
    x2 = (- b - sqrt(delta)) / (2 * a);

    if (a == 0)
        printf("%.2f", - c / b);
    else if (delta < 0)
        printf("NO");
    else if (delta == 0)
        printf("%.2f", - b / (2 * a));
    else {
        if (x1 > x2)
            printf("%.2f %.2f", x1, x2);
        else
            printf("%.2f %.2f", x2, x1);
    }
    /* average if/else fan vs average switch/case enjoyer */
    return 0;
}