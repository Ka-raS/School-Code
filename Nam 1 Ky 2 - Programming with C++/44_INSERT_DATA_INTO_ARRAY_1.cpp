#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int A[n];
    int B[m];

    int i;
    for (i = 0; i < n; i++)
        cin >> A[i];
    for (i = 0; i < m; i++)
        cin >> B[i];

    int insert;
    cin >> insert;

    i = 0;
    while (i < insert) {
        cout << A[i] << " ";
        i++;
    }
    
    for (int j = 0; j < m; j++)
        cout << B[j] << " ";
    
    while (i < n) {
        cout << A[i] << " ";
        i++;
    }
    cout << endl;

    return 0;
}