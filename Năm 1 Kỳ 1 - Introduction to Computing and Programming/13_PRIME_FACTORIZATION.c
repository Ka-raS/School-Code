#include<stdio.h>

int main(void) {
    int testCases;
    scanf("%d", &testCases);

    while(testCases--) {
        long long N;
        scanf("%lld", &N);

        while(N % 2 == 0) {
            printf("2 ");
            N /= 2;
        }
        for (long long i = 3; i * i <= N; i += 2)
            while (N % i == 0) {
                printf("%lld ", i);
                N /= i;
            }
        printf("%lld\n", N);
    }
    return 0;
}