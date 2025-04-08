#include <bits/stdc++.h>
#include <vector>
using namespace std;

int mod = 1000000007;

int findMod(long long n, int p) {
    if (!n) {
        if (!p)
            return 1;
        return 0;
    }
    if (p == 1)
        return n;

    long long res = 1;

    while (p) {
        if (p & 1)  // p % 2 == 1
            res = (res * n) % mod;

        // p % 2 == 0
        p = p >> 1; // p /= 2
        n = (n * n) % mod; 
    }
    return res;
}

int answer(vector<int> A, int n) {
    if (n == 1)
        return findMod(A[0], A[0]);

    long long h = (A[0] * A[1]) % mod;
    int g = __gcd(A[0], A[1]);

    int i = 2;
    while (i < n && g > 1) {
        h = (h * A[i]) % mod;
        g = __gcd(g, A[i]);
        i++;
    }
    
    while (i < n) {
        h = (h * A[i]) % mod;
        i++;
    }

    if (g == 1)
        return h;

    return findMod(h, g);
}

int main() {
    int n, x;

    int T;
    cin >> T;

    while (T--) {
        cin >> n;

        vector<int> A;

        for (int i = 0; i < n; i++) {
            cin >> x;
            A.push_back(x);
        }

        cout << answer(A, n) << endl;
    }

    return 0;
}