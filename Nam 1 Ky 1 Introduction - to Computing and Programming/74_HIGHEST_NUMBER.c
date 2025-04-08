#include<stdio.h>
#define max 100

int main(void)
{
    int testCases;
    scanf("%d", &testCases);
    while(testCases--)
    {
        int N, array[max] = {}, highestNumber, indices[max] = {}, j = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &array[i]);
            if(highestNumber < array[i] || i == 0)
                highestNumber = array[i];
        }
        for(int i = 0; i < N; i++)
            if(highestNumber == array[i])
            {
                indices[j] = i;
                j++;
            }
        printf("%d\n", highestNumber);
        for(int i = 0; i < j; i++)
            printf("%d ", indices[i]);
        printf("\n");
    }
    return 0;
}