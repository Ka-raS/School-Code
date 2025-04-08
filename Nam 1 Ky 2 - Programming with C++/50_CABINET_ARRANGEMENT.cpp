#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int A[n][n];

    int val = 0;
    int i, k;

    for (k = 1; k <= n; k++)
        for (i = 0; i < k; i++)
            A[i][n + i - k] = ++val;

    for (k = n - 1; k > 0; k--)
        for (i = 0; i < k; i++)
            A[n + i - k][i] = ++val;

    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++)
            cout << A[i][k] << " ";
        cout << endl;
    }

    return 0;
}