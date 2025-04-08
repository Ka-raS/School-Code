#include <iostream>
using namespace std;

long long primeMax(long long n) {
    while (!(n & 1))
        n /= 2;
            
    if (n == 1)
        return 2;       
        
    long long m;
    
    for (long long i = 3; i * i <= n; i += 2)
        if (!(n % i)) {
            m = i;
            
            while (!(n % i))
                n /= i;
        }
        
    if (n == 1)
        return m;
            
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    long long n;
    
    while (T--) {
        cin >> n;
        cout << primeMax(n) << endl;
    }
    
    return 0;           
}
    