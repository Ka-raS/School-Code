#include <iostream>
#define mod 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCases;
    cin >> testCases;
    
    int i, n, x;
    int a[2000];
    long long xn, ans;
    
    while (testCases--) {
        cin >> n >> x;

        for (i = 0; i < n; i++)
            cin >> a[i];

        ans = 0;
        xn = 1;
        while (n--) {
            ans += a[n] * xn;
            xn *= x;

            ans %= mod;
            xn %= mod;
        }
        
        cout << ans % mod << endl;        
    }
    
    return 0;
}