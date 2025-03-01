#include <bits/stdc++.h>
using namespace std;

struct PhanSo {
    long long divisor, dividend;
};

void nhap(PhanSo& p) {
    cin >> p.divisor >> p.dividend;
}

void rutgon(PhanSo& p) {
    long long gcdivisor = __gcd(p.divisor, p.dividend);
    p.divisor /= gcdivisor;
    p.dividend /= gcdivisor;
}

void in(PhanSo p) {
    cout << p.divisor << '/' << p.dividend;
}

int main() {
	struct PhanSo p;
	nhap(p);
	rutgon(p);
	in(p);
	return 0;
}