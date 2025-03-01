#include<iostream>
using namespace std;

bool isPrime(int n) {
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void simplify(long long *n) {
    while (*n % 2 == 0)
        *n /= 2;

    while (*n % 3 == 0)
        *n /= 3;

    for (int i = 5; i * i <= *n; i += 2)
        while (*n % (i * i) == 0 && isPrime(i))
            *n /= i;
}

int main() {
    int testCases;
    cin >> testCases;

    long long x, y;

    while (testCases--) {
        cin >> x >> y;
        
        simplify(&x);
        simplify(&y);

        if (x == y)
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }

    return 0;
}