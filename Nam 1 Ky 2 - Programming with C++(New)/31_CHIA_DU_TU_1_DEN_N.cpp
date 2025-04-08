#include <iostream>

using namespace std;

long long ans(long long n, long long k) {
    long long sum = n / k * k * (k - 1) / 2;
    
    if (n % k) {
        n -= n / k * k;
        sum += n * (n + 1) / 2;
    }
        
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> k;
        cout << ans(n, k) << endl;
    }

    return 0;
}