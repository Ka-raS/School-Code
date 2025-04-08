#include<stdio.h>

long long tenPoweri(int i){
    if(i == 0)
        return 1;
    return 10 * tenPoweri(--i);
}

void findMinMax(long long n, long long *min, long long *max){
    *min = 0, *max = 0;
    for(int i = 0; n != 0; i++){
        int digit = n % 10;
        long long pow = tenPoweri(i);
        if(digit == 5)
            digit = 6;
        *max += digit * pow;
        if(digit == 6)
            digit = 5;
        *min += digit * pow;
        n /= 10;
    }
}

int main(int argc, char* argv[]){
    int testCases;
    scanf("%d", &testCases);
    while(testCases--){
        long long a, b;
        scanf("%lld%lld", &a, &b);
        long long aMin, aMax, bMin, bMax;
        findMinMax(a, &aMin, &aMax);
        findMinMax(b, &bMin, &bMax);
        printf("%lld %lld\n", aMin + bMin, aMax + bMax);
    }
    return 0;
}