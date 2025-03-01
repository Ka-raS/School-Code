#include <bits/stdc++.h>
using namespace std;

struct PhanSo {
    long long divisor, dividend;
};

void nhap(PhanSo& a) {
    cin >> a.divisor >> a.dividend;
}

PhanSo tong(PhanSo p, PhanSo q) {

    p.divisor *= q.dividend;
    q.divisor *= p.dividend;

    p.divisor += q.divisor;
    p.dividend *= q.dividend;

    long long gcdi = __gcd(p.divisor, p.dividend);
    p.divisor /= gcdi;
    p.dividend /= gcdi;

    return p;
}

void in(PhanSo t) {
    cout << t.divisor << '/' << t.dividend;
}

int main() {
	struct PhanSo p,q;
	nhap(p); nhap(q);
	PhanSo t = tong(p,q);
	in(t);
	return 0;
}