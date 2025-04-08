#include <iostream>

using namespace std;

int ans(int a, int m) {
    for (int x = 1; x < m; x++)
        if (a * x % m == 1)
            return x;
            
    return -1;        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, m;

    int T;
    cin >> T;

    while (T--) {
        cin >> a >> m;
        cout << ans(a, m) << endl;
    }

    return 0;
}