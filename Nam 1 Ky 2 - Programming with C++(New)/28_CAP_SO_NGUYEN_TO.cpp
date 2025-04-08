#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (!(n & 1) || !(n % 3))
        return false;

    for (int i = 5; i * i <= n; i += 6)
        if (!(n % i) || !(n % (i + 2)))
            return false;

    return true;
}

void printAns(int n) {
    if (isPrime(n - 2)) {
        cout << "2 " << n - 2 << endl;
        return;
    }    
            
    for (int i = 3; i <= n / 2; i += 2)
        if (isPrime(i) && isPrime(n - i)) {
            cout << i << " " << n - i << endl;
            return;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        printAns(n);
    }

    return 0;
}