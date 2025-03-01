#include <iostream>
using namespace std;

long long power_mod(long long x, long long y, long long p) {
    long long result = 1;
    x = x % p;
    while (y > 0) {
        if (y % 2 == 1)
            result = (result * x) % p;

        y = y / 2;
        x = (x * x) % p;
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long x, y, p;
        cin >> x >> y >> p;
        long long result = power_mod(x, y, p);
        cout << result << endl;
    }
    return 0;
}
