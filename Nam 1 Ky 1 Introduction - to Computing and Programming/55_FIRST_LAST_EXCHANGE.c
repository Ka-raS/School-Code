#include<stdio.h>

int counting_digits(int number)
{
    if (number == 0)
        return 0;
    return 1 + counting_digits(number / 10);
}

void exchange(int array[9], int number, int number_of_digits)
{
    for(int i = number_of_digits - 1, digit; i >= 0; i--, number /= 10)
    {
        digit = number % 10;
        if(i == number_of_digits - 1)
            array[0] = digit;
        else if(i == 0)
            array[number_of_digits - 1] = digit;
        else
            array[i] = digit;
    }
}

void result(int array[9], int number_of_digits)
{
    for(int i = 0, flag = 0; i < number_of_digits; i++)
    {
        if(array[i] != 0)
            flag = 1;
        if(flag == 1)
            printf("%d", array[i]);
    }
}

int main(void)
{
    int number, array[9] = {};
    scanf("%d", &number);
    int number_of_digits = counting_digits(number);
    exchange(array, number, number_of_digits);
    result(array, number_of_digits);
    return 0;
}