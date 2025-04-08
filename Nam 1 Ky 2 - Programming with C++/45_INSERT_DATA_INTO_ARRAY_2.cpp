#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, p;

    int Ts;
    cin >> Ts;

    for (int t = 1; t <= Ts; t++) {
        cin >> N >> M >> p;

        int A[N];
        int B[M];

        int i;
        for (i = 0; i < N; i++)
            cin >> A[i];
        for (i = 0; i < M; i++)
            cin >> B[i];

        cout << "Test " << t << ":" << endl;

        i = 0;
        while (i < p) {
            cout << A[i] << " ";
            i++;
        }
        for (int j = 0; j < M; j++)
            cout << B[j] << " ";

        while (i < N) {
            cout << A[i] << " ";
            i++;
        }
        cout << endl;
    }
    return 0;
}