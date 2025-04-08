#include<iostream>
using namespace std;

int sumDigits(long long n) {
    int sum = 0;

    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    int testCases;
    cin >> testCases;

    long long n;

    while (testCases--) {
        cin >> n;

        while (n / 10 != 0)
            n = sumDigits(n);

        cout << n << endl;
    }

    return 0;
}