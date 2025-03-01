#include <iostream>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    
    int length;
    
    while (testCases--) {
        cin >> length;
        
        int max = 0, temp;
        
        for (int i = 0; i < length; i++) {
            cin >> temp;
            if (temp > max)
                max = temp;
        }
        
        cout << max << endl;        
    }
    
    return 0;
}