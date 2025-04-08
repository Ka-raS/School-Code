#include<stdio.h>

int palindromic_array()
{
    int length, result = 1, x = 0;
    scanf("%d", &length);
    int y = length - 1;
    int array[length];
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    if(length % 2 == 0)
        for(x, y; x != y - 1; x++, y--)
        {
            if (array[x] != array[y])
            {
                result = 0;
                break;
            }
        }
    else
        for(x, y; x != y; x++, y--)
        {
            if (array[x] != array[y])
            {
                result = 0;
                break;
            }
        }
    return result;
}

int main(void)
{
    int test_cases;
    scanf("%d", &test_cases);
    for(int case_no = 0; case_no < test_cases; case_no++)
    {
        int result = palindromic_array();
        if (result == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}