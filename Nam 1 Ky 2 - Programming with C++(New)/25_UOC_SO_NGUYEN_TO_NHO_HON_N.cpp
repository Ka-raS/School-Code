#include <iostream>
using namespace std;

bool isPrime(int n) {
    for (int i = 5; i * i <= n; i += 6)
        if (!(n % i) || !(n % (i + 2)))
            return false;
            
    return true;        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    int i, n;
    
    while (T--) {
        cin >> n;
        
        if (n >= 2)
            cout << 2 << " ";
    
        if (n >= 3)
            cout << 3 << " ";
    
        n -= 2;
        
        for (i = 5; i <= n; i += 6) {
            if (isPrime(i))
                cout << i << " ";
            if (isPrime(i + 2))
                cout << i + 2 << " ";  
        }          
        
        n += 2;
        if (5 <= i && i <= n && isPrime(i))
            cout << i << " ";
        
        i += 2;    
        if (5 <= i && i <= n && isPrime(i))
            cout << i << " ";
        
        cout << endl;
    }
    
    return 0;           
}