#include<stdio.h>
#include<math.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    for(int i = 0; i < test_cases; i++)
    {
        long long N, result;
        scanf("%lld", &N);
        result = sqrt(N);
        if (result*result == N)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}