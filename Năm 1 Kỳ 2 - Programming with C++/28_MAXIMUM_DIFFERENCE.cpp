#include <iostream>
#include <vector>
using namespace std;

void input(vector<int>& A, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        A.push_back(x);
    }
}

int sumMax(vector<int> A, vector<int> B, int n, int m) {
    int i;
    int sum = 0;

    for (i = 0; i < m; i++)
        sum += B[i];

    int sumMax = sum;

    for (i = 0; i < m; i++) {
        sum += A[i] - B[i];

        if (sumMax < sum)
            sumMax = sum;
    }

    while (i < n)
        sum += A[i++];

    if (sumMax < sum)
        sumMax = sum;

    for (i = 0; i < m; i++) {
        sum += B[i] - A[i];

        if (sumMax < sum)
            sumMax = sum;
    }

    return sumMax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<int> A, B;

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m;

        input(A, n);
        input(B, m);

        if (n > m)
            cout << sumMax(A, B, n, m) << endl;
        else
            cout << sumMax(B, A, m, n) << endl;
        
        A.clear();
        B.clear();
    }

    return 0;
}