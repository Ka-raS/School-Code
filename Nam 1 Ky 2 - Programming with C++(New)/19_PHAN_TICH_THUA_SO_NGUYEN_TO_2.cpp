#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
        
    int count = 0;
    
    if (!(n & 1)) {
        while (!(n & 1)) {
            n /= 2;
            count++;
        }
        
        cout << 2 << " " << count << endl;
    }
    
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) {
            count = 0;
            
            while (n % i == 0) {
                n /= i;
                count++;
            }
            
            cout << i << " " << count << endl;
        }
        
    if (n != 1)
        cout << n << " 1";    
    
    return 0;           
}