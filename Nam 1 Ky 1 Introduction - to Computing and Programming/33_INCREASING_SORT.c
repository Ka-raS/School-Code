#include<stdio.h>

void bubble_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print_array(int array[], int numbers)
{
    for(int i = 0; i < numbers; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    int length, array[99];
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    bubble_sort(array, length);
    print_array(array, length);
    return 0;
}