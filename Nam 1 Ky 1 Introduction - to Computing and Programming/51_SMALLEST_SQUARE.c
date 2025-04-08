#include<stdio.h>

void input(int x[4], int y[4])
{
    for(int i = 0; i < 4; i++)
        scanf("%d%d", &x[i], &y[i]);
}

void largest_absolute(int a[4], int *temp)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int absolute = a[i] - a[j];
            if(absolute < 0)
                absolute = -absolute;
            if(*temp < absolute)
                *temp = absolute;
        }
    }
}

int output(int x, int y)
{
    if(x > y)
        return x * x;
    else
        return y * y;
}

int main(void)
{
    int x[4], y[4], x_temp = 0, y_temp = 0;
    input(x, y);
    largest_absolute(x, &x_temp);
    largest_absolute(y, &y_temp);
    printf("%d", output(x_temp, y_temp));
    return 0;
}