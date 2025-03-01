#include<stdio.h>

void appearance_counts(int array[], int length)
{
    int array_occurences[99];
    for(int i = 0; i < length; i++)
    {
        int count = 1;
        for(int j = i + 1; j < length; j++)
        {
            if(array[i] == array[j])
            {
                count++;
                array[j] = -1;
            }
        }
        array_occurences[i] = count;
    }
    for(int i = 0; i < length; i++)
        if(array[i] != -1)
            printf("%d %d\n", array[i], array_occurences[i]);
}

int main(void)
{
    int length, array[99];
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    appearance_counts(array, length);
}