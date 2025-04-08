#include <stdio.h>

void interchange_sort(int array[], int length)
{
    for(int i = 0 ; i < length - 1 ; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            if(array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        printf("Step %d: ", i + 1);
        for (int index = 0; index < length; index++)
            printf("%d ", array[index]);
        printf("\n");
    }
}

int main()
{
    int length, array[99];
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    interchange_sort(array, length);
    return 0;
}