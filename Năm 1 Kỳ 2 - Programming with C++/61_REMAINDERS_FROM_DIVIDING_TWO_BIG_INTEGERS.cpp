#include <iostream>
using namespace std;

long long remainder(string N, long long M) {
    int lenN = N.length();
    if (lenN <= 18)
        return stoll(N) % M;

    long long result = 0;
    for (int i = 0; i < lenN; ++i) {
        result *= 10;
        result += N[i] - '0';
        result %= M;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    long long M;

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;
        cout << remainder(N, M) << endl;
    }
    return 0;
}