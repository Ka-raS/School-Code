#include <bits/stdc++.h>
using namespace std;

class PhanSo {
    private:
        long long divisor;
        long long dividend;

    public:
        PhanSo(long long a, long long b) {
            divisor = a;
            dividend = b;
        }

        friend istream& operator >> (istream& input, PhanSo& p) {
            input >> p.divisor >> p.dividend;
            return input;
        }

        void rutgon() {
            long long gcdiv = __gcd(divisor, dividend);
            divisor /= gcdiv;
            dividend /= gcdiv;
        }

        friend ostream& operator << (ostream& output, const PhanSo p) {
            output << p.divisor << '/' << p.dividend;
            return output;
        }
};

int main() {
	PhanSo p(1,1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}