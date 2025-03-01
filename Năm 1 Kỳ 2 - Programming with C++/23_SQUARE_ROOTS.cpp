#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    
    int n;
    
    while (testCases--) {
        cin >> n;
        
        double result = 0;
        
        for (int i = 1; i <= n; i++)
            result = sqrt(i + result);
            
        printf("%.5f\n", result);    
    }
            
    return 0;
}