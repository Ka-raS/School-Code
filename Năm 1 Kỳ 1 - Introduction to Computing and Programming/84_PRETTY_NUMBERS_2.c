#include<stdio.h>
#include<math.h>

int isPretty(int i){
    int iOriginal = i, iReversed = 0, sum = 0;
    while(i){
        int digit = i % 10;
        sum += digit;
        iReversed = iReversed * 10 + digit;
        i /= 10;
    }
    if(iOriginal != iReversed || sum % 10 != 0)
        return 0;
    return 1;
}

int main(int argc, char* argv[]){
    int testCases;
    scanf("%d", &testCases);
    while(testCases--){
        int digits;
        scanf("%d", &digits);
        int max = pow(10, digits), count = 0;
        for(int i = max / 10; i < max; i++)
            if(isPretty(i))
                count++;
        printf("%d\n", count);
    }
    return 0;
}