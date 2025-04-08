#include<iostream>
using namespace std;

bool isAllEven(long long N) {
    while (N) {
        if ( (N % 10)&1 )
            return false;
        N /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;

    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        if ((N&1) == 0 && isAllEven(N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}