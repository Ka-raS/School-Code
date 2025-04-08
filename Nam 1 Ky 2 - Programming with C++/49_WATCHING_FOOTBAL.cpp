#include <iostream>
using namespace std;

int ans(int* A, int n) {
    if (A[0] > 15)
        return 15;

    for (int i = 0; i < n; i++) {
        if (A[i] > 74)
            return 90;

        if (A[i + 1] - A[i] > 15)
            return A[i] + 15;
    }
    if (A[n] > 74)
        return 90;

    return A[n] + 15;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << ans(A, n - 1) << endl;

    return 0;
}