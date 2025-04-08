#include<stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selection_sort(int array[], int length)
{
    int i, j, min_idex;
    for (i = 0; i < length - 1; i++)
    {
        min_idex = i;
        for (j = i + 1; j < length; j++)
            if (array[j] < array[min_idex])
                min_idex = j;
            if(min_idex != i)
                swap(&array[min_idex], &array[i]);
        printf("Step %d: ", i + 1);
        for (int index = 0; index < length; index++)
            printf("%d ", array[index]);
        printf("\n");
    }
}

int main(void)
{
    int length, array[99];
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    selection_sort(array, length);
    return 0;
}