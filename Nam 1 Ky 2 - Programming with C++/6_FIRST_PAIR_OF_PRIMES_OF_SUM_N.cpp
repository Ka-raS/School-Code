#include<iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if ((n & 1) == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int N;
        cin >> N;

        if (isPrime(N - 2))
            printf("2 %d\n", N - 2);
        else {
            int flag = 1;
            for (int i = 3; i <= N / 2; i += 2)
                if (isPrime(i) && isPrime(N - i)) {
                    printf("%d %d\n", i, N - i);
                    flag = 0;
                    break;
                }
            if (flag)
                cout << -1 << endl;
        }
        
    }
    
    return 0;
}