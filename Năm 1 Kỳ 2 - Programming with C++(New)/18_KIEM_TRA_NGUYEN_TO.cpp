#include <iostream>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if ((n & 1) == 0 || n % 3 == 0)
        return false;
        
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
            
    return true;             
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
        
    if (isPrime(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;           
}