#include <iostream>
#include <vector>
using namespace std;

void printMinMax(int m, int s) {
    int i;
    vector<int> N;

    i = m - (s - 1) / 9;
    N.assign(m, 9);
    N.assign(i, 0);
    N[0] = 1;

    if (i >= 0)
        N[i - 1] += (s - 1) % 9;

    for (i = 0; i < m; i++)
        cout << N[i];
    cout << " ";
    
    i = s / 9;
    N.assign(m, 0);
    N.assign(i, 9);

    if (i < m)
        N[i] = s % 9;

    for (i = 0; i < m; i++)
        cout << N[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s;
    cin >> m >> s;

    if (s > 9 * m || !s)
        cout << "-1 -1";
    else
        printMinMax(m, s);

    return 0;
}