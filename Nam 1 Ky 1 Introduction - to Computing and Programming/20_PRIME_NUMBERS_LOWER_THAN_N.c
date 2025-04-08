#include <stdio.h>

int ktra(int k)
{
	if(k == 2)
		return 1;
	else if(k < 2 || k % 2 == 0)
		return 0;
	for(int i = 3; i * i <= k; i += 2)
		if(k % i == 0)
			return 0;
    return 1;
}

int main()
{
	long n;
	scanf("%ld", &n);
	for(long m = 2; m <= n; ++m)
		if(ktra(m))
			printf("%ld\n", m);
	return 0;
}