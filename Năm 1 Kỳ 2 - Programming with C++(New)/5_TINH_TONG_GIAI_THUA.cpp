#include <iostream>
using namespace std;

long long sumFact(int n) {
    long long sum = 1;
    long long nFact = 1;
    
    for (int i = 2; i <= n; i++) {
        nFact *= i;
        sum += nFact;
    }
    
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << sumFact(n) << endl;
}
    