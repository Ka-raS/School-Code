#include <bits/stdc++.h>
using namespace std;

struct PhanSo
{
    long long tu, mau;
};

long long __lcm(const long long a, const long long b)
{
    return a / __gcd(a, b) * b;
}

void toigian(PhanSo &A)
{
    int div = __gcd(A.tu, A.mau);
    A.tu /= div;
    A.mau /= div;
}

void process(const PhanSo &A, const PhanSo &B)
{
    PhanSo C;
    C.mau = __lcm(A.mau, B.mau);
    C.tu = A.tu * (C.mau / A.mau) + B.tu * (C.mau / B.mau);
    toigian(C);
    C.tu *= C.tu;
    C.mau *= C.mau;

    PhanSo D;
    D.tu = A.tu * B.tu * C.tu;
    D.mau = A.mau * B.mau * C.mau;
    toigian(D);

    cout << C.tu << '/' << C.mau << ' '
         << D.tu << '/' << D.mau << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        PhanSo A;
        PhanSo B;
        cin >> A.tu >> A.mau >> B.tu >> B.mau;
        process(A, B);
    }
}