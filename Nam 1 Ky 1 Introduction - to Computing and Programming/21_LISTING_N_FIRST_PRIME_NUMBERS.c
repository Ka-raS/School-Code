#include<stdio.h>

int prime(int i)
{
    if(i == 2)
        return 1;
    else if(i < 2 || i % 2 == 0)
        return 0;
    for(int j = 3; j * j <= i; j += 2)
        if(i % j == 0)
            return 0;
    return 1;
}

int main(void)
{
    long a = 2, numbers, line = 0;
    scanf("%ld", &numbers);
    while(line < numbers)
    {    
        if(prime(a))
        {
            printf("%ld\n", a);
            ++line;
        }
        ++a;
    }
    return 0;
}