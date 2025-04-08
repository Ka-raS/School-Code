#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isPretty(int i){
    int iOriginal = i, iReversed = 0, sum = 0, has6 = 0;
    while(i){
        int digit = i % 10;
        if(digit == 6)
            has6 = 1;
        sum += digit;
        iReversed = iReversed * 10 + digit;
        i /= 10;
    }
    if(has6 == 0 || iOriginal != iReversed || sum % 10 != 8)
        return 0;
    return 1;
}

int main(int argc, char* argv[]){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a > b)
        swap(&a, &b);
    for(int i = a; i <= b; i++)
        if(isPretty(i))
            printf("%d ", i);
    return 0;
}