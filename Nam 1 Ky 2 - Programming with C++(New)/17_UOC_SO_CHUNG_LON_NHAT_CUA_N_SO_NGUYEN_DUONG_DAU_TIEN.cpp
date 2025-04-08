#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);    
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    int i, n;
    long long ans;
    
    while (T--) {
        cin >> n;
        
        ans = 1;
        
        for (i = 2; i <= n; i++)
            ans = lcm(ans, i);
            
        cout << ans << endl;
    }
    
    return 0;           
}