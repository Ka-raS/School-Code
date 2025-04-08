#include<stdio.h>
#include<stdint.h>
#include <inttypes.h>

char *non_decreasing_number(uint64_t n)
{
    while(n != 0)
    {
        int digit_right = n % 10;
        n /= 10;
        int digit_left = n % 10;
        if(digit_right < digit_left)
            return "NO";
    }
    return "YES";
}

int main(int test_cases)
{
    scanf("%d", &test_cases);
    for(int test = 0; test < test_cases; test++)
    {
        uint64_t number;
        scanf("%"PRIu64, &number);
        printf("%s\n", non_decreasing_number(number));
    }
    return 0;
}