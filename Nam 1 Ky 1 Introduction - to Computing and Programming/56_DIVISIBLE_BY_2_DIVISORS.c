#include<stdio.h>

int main(int test_cases)
{
	scanf("%d", &test_cases);
	while(test_cases--)
    {
        int N, count = 0;
		scanf("%d", &N);
		for(int i = 1; i * i <= N; i++)
			if(N % i == 0)
            {
				if(i % 2 == 0) 
					count++;
				if((N / i) % 2 == 0)
					count++;
				if(i*i == N && i % 2 == 0)
					count--;
			}
		printf("%d\n", count);
	}
	return 0;
}