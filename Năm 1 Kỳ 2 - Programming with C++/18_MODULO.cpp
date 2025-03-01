#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long diff1 = abs(a - b);
    long long diff2 = abs(b - c);
    long long diff3 = abs(c - d);

    long long gcd1 = gcd(diff1, diff2);
    long long gcd2 = gcd(gcd1, diff3);

    cout << gcd2 << endl;

    return 0;
}
/*  0__a___b_______c___________d
+)  chia đoạn ad thành các đoạn băng nhau, a b c d phải là đầu mút
       a___b___.___c___.___.___d
       .___.___.___.___.___.___.
+)  lùi đoạn trên trục số sao cho 0 là một đầu mút
    .___.___.___.___.___.___.
    .___.___.___.___.___.___.___.
    0__a.__b.___.__c.___.___.__d
    .__a.__b____.__c________.__d (phần dư bằng nhau)
*/    