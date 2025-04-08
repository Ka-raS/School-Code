#include <bits/stdc++.h>
using namespace std;

bool isSatisfied(long long n, long long m) {
    long long sumAll = n * (n + 1) / 2;

    if (sumAll < m)
        return false;

    long long sum1 = (sumAll + m) / 2;
    long long sum2 = sumAll - sum1;

    if (sum1 + sum2 == sumAll && sum1 - sum2 == m)
        return __gcd(sum1, sum2) == 1;
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m;

    int T;
    cin >> T;

     while (T--) {
        cin >> n >> m;
        
        if (isSatisfied(n, m))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;    
    }

    return 0;
}