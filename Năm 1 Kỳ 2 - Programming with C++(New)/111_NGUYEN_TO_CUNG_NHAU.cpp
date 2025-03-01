#include <bits/stdc++.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}    

bool isPrime(const int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    int root = sqrt(n);
    
    for (int i = 5; i <= root; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
            
    return true;        
}

bool check(const int n) {
    int count = 1;
    
    if (n & 1) {
        for (int i = 2; i < n; i++)
            if (gcd(i, n) == 1)
                count++;
    } else {
        for (int i = 3; i < n; i += 2)
            if (gcd(i, n) == 1)
                count++;
    }
        
    return isPrime(count);    
}

int main() {
    int t, n;
    std::cin >> t;
    
    while (t--) {
        std::cin >> n;
        std::cout << check(n) << '\n';
    }

    return 0;
}