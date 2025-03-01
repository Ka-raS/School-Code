#include <stdio.h>
#define max 100000

int main(int argc, char* argv[]) {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int length, A[max] = {0};

        scanf("%d", &length);
        for (int i = 0; i < length; i++)
            scanf("%d", &A[i]);
        
        long long maxSum = A[0], sumTemp = 0;

        for (int i = 0; i < length; i++) {
            sumTemp += A[i];
            if (maxSum < sumTemp)
                maxSum = sumTemp;
            if (sumTemp < 0)
                sumTemp = 0;
        }

        printf("%lld\n", maxSum);

    }
    return 0;
}