#include<stdio.h>

void sort(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isPrime(int i){
    if(i == 2)
        return 1;
    else if(i == 0 || i == 1 || (i & 1) == 0)
        return 0;
    for(int j = 3; j * j <= i; j += 2)
        if(i % j == 0)
            return 0;
    return 1;
}

int isFibonacci(int i){
    for(int a = 0, b = 1; i >= a || i >= b; a += b, b += a)
        if(i == a || i == b)
            return 1;
    return 0;
}

int isPretty(int i){
    if(isPrime(i) == 0)
        return 0;
    int sum = 0;
    while(i){
        sum += i % 10;
        i /= 10;
    }
    if(isFibonacci(sum))
        return 1;
    return 0;
}

int main(int argc, char* argv[]){
    int a, b;
    scanf("%d%d", &a, &b);
    if(a > b)
        sort(&a, &b);
    for(int i = a; i <= b; i++)
        if(isPretty(i))
            printf("%d ", i);
    return 0;
}