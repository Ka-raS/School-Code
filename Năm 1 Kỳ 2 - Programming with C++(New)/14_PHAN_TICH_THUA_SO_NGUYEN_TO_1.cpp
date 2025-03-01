#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    int n, count, i;
    
    while (T--) {
        cin >> n;
        
        count = 0;
        while (!(n & 1)) {
            count++;
            n /= 2;
        }    
            
        if (count)
            cout << "2 " << count << " ";
            
        for (i = 3; i * i <= n; i += 2) {
            count = 0;
            
            while (!(n % i)) {
                count++;
                n /= i;
            }
            
            if (count)
                cout << i << " " << count << " ";
        }
        
        if (n != 1)
            cout << n << " " << 1;
            
        cout << endl;
    }
    
    return 0;           
}