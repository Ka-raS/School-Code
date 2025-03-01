#include<iostream>
using namespace std;

int sumDigits(int n) {
    int sum = 0;

    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int testCases;
    cin >> testCases;

    long long n;

    while (testCases--) {
        cin >> n;
        
        while (gcd(n, sumDigits(n)) <= 1)
            n++;
        
        cout << n << endl;
    }

    return 0;
}