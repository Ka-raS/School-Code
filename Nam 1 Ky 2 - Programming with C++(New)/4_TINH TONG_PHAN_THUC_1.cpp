#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(4) << fixed;

    int N;
    double M = 0;

    cin >> N;

    for (double i = 1; i <= N; i++)
        M += 1 / i;

    cout << M << endl;

    return 0;
}