#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    long long n;
    
    while (T--) {
        cin >> n;
        
        while (!(n & 1)) {
            cout << 2 << "  ";
            n /= 2;
        }    
            
        for (long long i = 3; i * i <= n; i += 2)
            while (!(n % i)) {
                cout << i << "  ";
                n /= i;
            }
        
        if (n != 1)
            cout << n;
            
        cout << endl;
    }
    
    return 0;           
}