#include <stdio.h>
#define max 100

int main(void)
{
    int value[7] = {1, 5, 10, 50, 100, 500, 1000};
    int symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int testCases;
    scanf("%d\n", &testCases);
    while(testCases--)
    {
        char string[max] = {};
        gets(string);
        int decimalValue = 0;
        for(int i = 0; string[i] != '\0'; i++)
        {
            int temp1 = 0, temp2 = 0;
            for(int j = 0; j < 7; j++)
            {
                if(string[i] == symbol[j])
                    temp1 = value[j];
                if(string[i + 1] == symbol[j])
                    temp2 = value[j];
            }
            if(temp1 >= temp2)
                decimalValue += temp1;
            else
                decimalValue -= temp1;
        }
        printf("%d\n", decimalValue);
    }
    return 0;
}