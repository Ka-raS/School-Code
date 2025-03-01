#include <bits/stdc++.h>

long long pow10(int n) {
    long long product = 1;
    
    while (n--)
        product *= 10;
        
    return product;   
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);    
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int t;
    std::cin >> t;
    
    int n;
    long long x, y, z, ans, multiple;
    
    while (t--) {
        std::cin >> x >> y >> z >> n;
        
        ans = pow10(n - 1);
        multiple = lcm(x, lcm(y, z));
        
        if (ans * 10 - 1 < multiple)
            ans = -1;
        else if (ans % multiple)
            ans += - (ans % multiple) + multiple;
        
        std::cout << ans << '\n';
    }

    return 0;
}