#include<stdio.h>
#define max 99

void input(int array[], int length)
{
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
}

void uniting(int a[], int b[], int n, int m)
{
    for(int i = n, j = 0; i < n + m; i++, j++)
        a[i] = b[j];
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

void remove_duplicates(int array[], int *length)
{
    for(int i = 0; i < *length - 1; i++)
    {
        for(int j = i + 1; j < *length; j++)
        {
            if(array[i] == array[j])
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
}

int main(void)
{
    int a[max], b[max], n, m;
    scanf("%d%d", &n, &m);
    input(a, n);
    input(b, m);
    uniting(a, b, n, m);
    int length =  n + m;
    bubble_sort(a, length);
    remove_duplicates(a, &length);
    print_array(a, length);
    return 0;
}