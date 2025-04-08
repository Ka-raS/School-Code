#include<stdio.h>

long long factorial(long long i)
{
    if (i == 0)
        return 1;
    else
        return i * factorial(i - 1);
}

long long pascal(long long row, long long column)
{
    return factorial(row) / (factorial(column) * factorial(row - column));
}

int main(void)
{
    long long line, row = 0, column = 0;
    scanf("%lld", &line);
    while(row < line)
    {
        if(row < column)
        {
            printf("\n");
            column = 0;
            ++row;
        }
        else
        {
            printf("%lld ", pascal(row, column));
            ++column;
        }
    }
    return 0;
}