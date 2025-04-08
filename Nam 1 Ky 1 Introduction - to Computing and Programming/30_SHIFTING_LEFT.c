#include<stdio.h>

void shift(int array[], int length, int shift_steps)
{
    for(int i = shift_steps; i < length; i++)
        printf("%d ", array[i]);
    for(int i = 0; i < shift_steps; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    int length, array[99], shift_steps;
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    scanf("%d", &shift_steps);
    shift(array, length, shift_steps);
    return 0;
}