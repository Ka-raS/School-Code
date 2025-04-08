#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 3)
        return true;
    if (!(n & 1) || !(n % 3))
        return false;

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
    
    int n, i;
    
    while (T--) {
        cin >> n;
        
        for (i = 2; i * i < n; i++)
            if (isPrime(i))
                cout << i * i << " ";
                
        cout << endl;        
    }
    
    return 0;           
}