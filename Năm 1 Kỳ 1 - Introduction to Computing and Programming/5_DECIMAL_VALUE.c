#include<stdio.h>

int main(int argc, char* argv[]) {
    int testCases;
    scanf("%d", &testCases);
    
    while (testCases--) {
        int N;
        scanf("%d", &N);
        printf("%.15lf\n", (double)1 / N);
    }
    return 0;
}