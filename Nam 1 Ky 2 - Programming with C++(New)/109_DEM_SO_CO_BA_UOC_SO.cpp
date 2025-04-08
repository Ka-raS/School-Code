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
    int t, i, root;
    long long n, count;
    const int size = 1000002;

    bool a[size];
    a[2] = 1, a[3] = 1;
    
    for (i = 5; i < size; i += 6) {
        a[i] = isPrime(i);
        a[i + 2] = isPrime(i + 2);
    }    
        
    std::cin >> t;
    
    while (t--) {
        std::cin >> n;
        
        count = n >= 4;
        root = sqrt(n);
        
        for (i = 3; i <= root; i += 2)
            count += a[i];
            
        std::cout << count << '\n';
    }

    return 0;
}