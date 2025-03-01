#include<stdio.h>

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
    print_array(even_array, a);
    print_array(odd_array, b);
    return 0;
}