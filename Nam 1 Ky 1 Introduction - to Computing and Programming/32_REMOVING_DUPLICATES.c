#include<stdio.h>

void remove_duplicates(int array[], int length)
{
    for(int i = 0; i < length; i++)
        for(int j = i + 1; j < length; j++)
            if(array[i] == array[j])
                array[j] = -1;
    for(int i = 0; i < length; i++)
        if(array[i] != -1)
            printf("%d ", array[i]);
}

int main(void)
{
    int length, array[99];
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    remove_duplicates(array, length);
    return 0;
}