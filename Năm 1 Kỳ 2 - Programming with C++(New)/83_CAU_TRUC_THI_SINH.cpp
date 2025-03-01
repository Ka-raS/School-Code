#include <bits/stdc++.h>
using namespace std;

struct ThiSinh {
    string name, date;
    double i, ii, iii;
};

void nhap(ThiSinh& A) {
    getline(cin, A.name);
    cin >> A.date >> A.i >> A.ii >> A.iii;
}

void in(ThiSinh A) {
    cout << A.name << ' ' << A.date << ' ' << fixed << setprecision(1) << A.i + A.ii + A.iii;
}

int main(){
    struct ThiSinh A;
    nhap(A);
    in(A);
    return 0;
}