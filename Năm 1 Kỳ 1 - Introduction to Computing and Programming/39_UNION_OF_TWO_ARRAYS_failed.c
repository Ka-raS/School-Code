#include<stdio.h>
#define max 99

void input(int array[], int length)
{
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
}

void uniting(int a[], int b[], int union_array[], int n, int m, int *index)
{
    for(int i = 0; i < n; i++, *index = *index + 1)
        union_array[*index] = a[i];
    for(int i = 0; i < m; i++, *index = *index + 1)
        union_array[*index] = b[i];
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
    }
}

void remove_duplicates(int array[], int *index)
{
    for(int i = 0; i < *index - 1; i++)
    {
        for(int j = i + 1; j < *index; j++)
        {
            if(array[i] == array[j])
            {
                for(int k = j; k < *index; k++)
                    array[k] = array[k + 1];
                *index = * index - 1;
                j--;
            }
        }
    }
}

void print_array(int array[], int length)
{
    for(int i = 0; i < length; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    int a[max], b[max], union_array[max], n, m, index = 0;
    scanf("%d%d", &n, &m);
    input(a, n);
    input(b, m);
    uniting(a, b, union_array, n, m, &index);
    bubble_sort(union_array, index);
    remove_duplicates(union_array, &index);
    print_array(union_array, index);
    return 0;
}