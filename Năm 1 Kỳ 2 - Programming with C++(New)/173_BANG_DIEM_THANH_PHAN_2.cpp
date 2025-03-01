#include <bits/stdc++.h>
using namespace std;

struct SinhVien
{
    string msv, lop, ten;
    float d1, d2, d3;
};

void nhap(SinhVien &A)
{
    cin.ignore();
    getline(cin, A.msv);
    getline(cin, A.ten);
    getline(cin, A.lop);
    cin >> A.d1 >> A.d2 >> A.d3;
}

void xuat(const SinhVien &A)
{
    cout << A.msv << ' '
         << A.ten << ' '
         << A.lop << ' '
         << fixed << setprecision(1)
         << A.d1 << ' '
         << A.d2 << ' '
         << A.d3 << '\n';
}

bool cmp(const SinhVien &A, const SinhVien &B)
{
    return A.ten < B.ten;
}

int main()
{
    int N;
    cin >> N;
    vector<SinhVien> SV(N);
    for (auto &M : SV)
        nhap(M);
    sort(SV.begin(), SV.end(), cmp);
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ' ';
        xuat(SV[i]);
    }

    return 0;
}