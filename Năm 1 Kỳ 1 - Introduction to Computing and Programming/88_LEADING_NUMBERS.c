#include<stdio.h>
#define max 1000

int isLeading(int a[], int i, int N){
    for(int j = i + 1; j < N; j++)
        if(a[i] <= a[j])
            return 0;
    return 1;
}

int main(int argc, char* argv[]){
    int testCases;
    scanf("%d", &testCases);
    while(testCases--){
        int N, a[max] = {0};
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < N; i++)
            if(isLeading(a, i, N))
                printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}