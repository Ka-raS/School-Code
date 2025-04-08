#include<iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        long long a, x, y;
        cin >> a >> x >> y;

        int loop = gcd(x, y);
        while (loop--)
            cout << a;
        cout << endl;
    }

    return 0;
}