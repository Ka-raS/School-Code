#include<stdio.h>
#define max 99

void insertion_sort(int array[], int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < i; j++)
        {   
            if(array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        printf("Step %d: ", i);
        for(int index = 0; index < i + 1; index++)
            printf("%d ", array[index]);
        printf("\n");
    }
}

int main(void)
{
    int length, array[max];
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    insertion_sort(array, length);
    return 0;
}