#include<stdio.h>

int main(int argc, char* argv[]) {
    int testCases;
    scanf("%d", &testCases);
    
    while (testCases--) {
        int N;
        scanf("%d", &N);
        printf("%lld\n", (long long)N * N);
    }
    return 0;
}