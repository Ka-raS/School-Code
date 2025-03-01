#include<iostream>
using namespace std;

long long ans(int k) {
    int rank = 0;
    int long long i = 0;

    while (++i)
        if (i % 10 != 3 && i % 3) {
            rank++;
            if (rank == k)
                return i;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    cout << ans(k) << endl;

    return 0;
}