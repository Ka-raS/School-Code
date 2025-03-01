#include<stdio.h>
#define max 99

void input(int array[], int length)
{
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
}

void output(int i, int array[], int length)
{
    printf("Step %d: ", i + 1);
    for(int index = 0; index < length; index++)
        printf("%d ", array[index]);
    printf("\n");
}

void bubble_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int flag = 0;
        for(int j = 0; j < length - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                flag = 1;
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        if (flag == 0)
            break;
        output(i, array, length);
    }
}

int main(void)
{
    int length, array[max];
    scanf("%d", &length);
    input(array, length);
    bubble_sort(array, length);
    return 0;
}