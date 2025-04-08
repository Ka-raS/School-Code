#include <iostream>
using namespace std;

int pow10 (int n) {
    if (!n)
        return 1;
    return 10 * pow10(n - 1);   
}

bool isSatisfied(int n) {
    int odds  = 0;
    int evens = 0;
    
    while (n) {
        if ((n % 10) & 1)
            odds++;
        else
            evens++;
            
        n /= 10;        
    }
    
    return odds == evens ? true : false;    
}

void printAns(int n) {
    if (n & 1)
        return;
    
    int count = 0;
    int end = pow10(n);
    
    for (int i = end / 10; i < end; i++) {
        if (isSatisfied(i)) {
            cout << i << " ";
            count++;
        }
        if (count == 10) {
            cout << endl;
            count = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    printAns(n);
    
    return 0;           
}