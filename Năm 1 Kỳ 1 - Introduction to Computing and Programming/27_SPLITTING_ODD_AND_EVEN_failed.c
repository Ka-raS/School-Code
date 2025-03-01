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

void remove_duplicates(int array[], int *length)
{
    for(int i = 0; i < *length - 1; i++)
    {
        for(int j = 0; j < *length - i - 1; j++)
        {
            if(array[j] == array[j + 1])
            {
                for(int k = j; k < *length; k++)
                    array[k] = array[k + 1];
                *length = * length - 1;
                j--;
            }
        }
    }
}

void print_array(int array[], int length)
{
    for(int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    int length, a = 0, b = 0;
    scanf("%d", &length);
    int array[length], even_array[99] = {0}, odd_array[99] = {0};
    for(int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
        if (array[i] % 2 == 0)
        {
            even_array[a] = array[i];
            a++;
        }
        else
        {
            odd_array[b] = array[i];
            b++;
        }
    }
    bubble_sort(even_array, a);
    remove_duplicates(even_array, &a);
    print_array(even_array, a);

    bubble_sort(odd_array, b);
    remove_duplicates(odd_array, &b);
    print_array(odd_array, b);
    return 0;
}