#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    long long N;
    
    while (T--) {
        cin >> N;
        cout << N * (N + 1) / 2 << endl;
    }
    
    return 0;
}