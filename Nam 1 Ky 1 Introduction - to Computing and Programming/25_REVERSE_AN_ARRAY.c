#include<stdio.h>

int main(void)
{
    int length;
    scanf("%d", &length);
    int array[length];
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    for(int x = length - 1; x >= 0; x--)
        printf("%d ", array[x]);
    return 0;
}