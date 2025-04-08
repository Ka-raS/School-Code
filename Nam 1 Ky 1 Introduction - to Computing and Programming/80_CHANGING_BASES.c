#include<stdio.h>

char character[36] ={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int main(int argc, char* argv[])
{
    int testCases;
    scanf("%d", &testCases);

    while(testCases--) {
        int N, b;
        scanf("%d%d", &N, &b);

        char NConverted[17];
        int i = 0;

        while(N != 0) {
            NConverted[i] = character[N % b];
            N /= b;
            i++;
        }

        while(i--)
            printf("%c", NConverted[i]);

        printf("\n");
    }
    return 0;
}