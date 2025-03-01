#include <bits/stdc++.h>

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

int main() {
    const int size = 100002;
    bool a[size];
    a[2] = 1, a[3] = 1;
    
    for (int i = 5; i < size; i += 6) {
        a[i] = isPrime(i);
        a[i + 2] = isPrime(i + 2);
    }    
        
    int t;
    std::cin >> t;
    
    int l, r, count;
    
    while (t--) {
        std::cin >> l >> r;
        
        count = 0;
        
        while (l <= r) {
            count += a[l];
            l++;
        }
            
        std::cout << count << '\n';
    }

    return 0;
}