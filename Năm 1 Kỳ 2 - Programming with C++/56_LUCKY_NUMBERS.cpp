#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isLucky(string n) {
    int i;
    int sum = 0;
    int len = n.length();

    for (i = 0; i < len; i++)
        sum += n[i] - 48;

    if (sum > 9) {
        i = 0;
        int numDigits = ceil(log10(sum));
        string m (numDigits, ' ');

        while (sum) {
            m[i] = sum % 10 + 48;
            sum /= 10;
            i++;
        }
        return isLucky(m);
    }
    if (sum == 9)
        return true;
    if (sum < 9)
        return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        cout << isLucky(n) << endl;
    }
    return 0;
}