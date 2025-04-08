#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    long long a, b;
    long long divisor;
    long long multiple;
    
    while (T--) {
        cin >> a >> b;
        
        divisor  = gcd(a, b);
        multiple = a / divisor * b;
        
        cout << multiple << "  " << divisor << endl;
    }
    
    return 0;           
}