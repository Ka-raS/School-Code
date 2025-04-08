#include<stdio.h>
#define max 100

void input(int *length, int A[max], int B[max])
{
    scanf("%d", &*length);
    for(int i = 0; i < *length; i++)
        scanf ("%d", &A[i]);
    for(int i = 0; i < *length; i++)
        scanf ("%d", &B[i]);
}

void ascending_sort(int array[max], int length)
{
    for(int i = 0; i < length; i++)
        for(int j = i + 1; j < length; j++)
            if(array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

void descending_sort(int array[max], int length)
{
    for(int i = 0; i < length; i++)
        for(int j = i + 1; j < length; j++)
            if(array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

void output(int A[max], int B[max], int length, int test)
{
    printf("Test %d:\n", test);
    for(int i = 0; i < length; i++)
        printf("%d %d ", A[i], B[i]);
    printf("\n");
}

int main(int test_cases)
{
    scanf("%d", &test_cases);
    for(int test = 1, length, A[max], B[max]; test <= test_cases; test++) 
    {
        input(&length, A, B);
        ascending_sort(A, length);
        descending_sort(B, length);
        output(A, B, length, test);
    }
    return 0;
}