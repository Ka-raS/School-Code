#include <stdio.h>

void print_array(int array[], int numbers)
{
    printf("%d\n", numbers);
    for(int i = 0; i < numbers; i++)
        printf("%d ", array[i]);
}

int count_occur(int array[], char flags[], int length, int value)
{
    int i, count = 0;
    for (i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            if (flags[i] != 0) 
                return 0;
            ++count;
        }
    }
    return count;
}

int main(void)
{
    char flags[99] = {0};
    int num_appear, i, length;
    scanf("%d", &length);
    int a[99], b[99], j = 0;
    for(i = 0; i < length; i++)
        scanf("%d", &a[i]); 
    for(i = 0; i < length; i++)
    {
        num_appear = count_occur(a, flags, length, a[i]);
        flags[i] = 1;
        if(num_appear == 1)
        {
            b[j] = a[i];
            j++;
        }
    }
    print_array(b, j);
    return 0;
}