#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 3)
        return true;
    if (!(n % 3))
        return false;
        
    for (int i = 5; i * i <= n; i += 6)
        if (!(n % i) || !(n % (i + 2)))
            return false;
            
    return true;        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, i;
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> a >> b;
    
        if (a <= 2)
            cout << 2 << "  ";
    
        if (!(a & 1))
            a++;
        
        for (i = a; i <= b; i += 2)
            if (isPrime(i))
                cout << i << "  ";
                
        cout << endl;        
    }
    
    return 0;           
}