#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    int n, sum;
    
    while (T--) {
        cin >> n;
        
        while (n > 9) {
            sum = 0;
            
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            
            n = sum;
        }
        
        cout << n << endl;
    }
    
    return 0;           
}