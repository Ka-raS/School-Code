#include <bits/stdc++.h>
using namespace std;

class PhanSo {
    private:
        long long dsor, dend;

    public:
        PhanSo (long long a, long long b) {
            dsor = a;
            dend = a;
        }

        friend istream& operator >> (istream& input, PhanSo& n) {
            input >> n.dsor >> n.dend;
            return input;
        }

        friend PhanSo operator + (const PhanSo a, const PhanSo b) {
            PhanSo sum(0, 0);
            sum.dsor = a.dsor * b.dend + b.dsor * a.dend;
            sum.dend = a.dend * b.dend;

            long long gcd = __gcd(sum.dsor, sum.dend);
            sum.dsor /= gcd;
            sum.dend /= gcd;

            return sum;
        }

        friend ostream& operator << (ostream& output, const PhanSo n) {
            output << n.dsor << '/' << n.dend;
            return output;
        }
};

int main() {
	PhanSo p(1,1), q(1,1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}