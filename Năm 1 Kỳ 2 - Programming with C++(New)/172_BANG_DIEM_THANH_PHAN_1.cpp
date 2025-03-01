#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using std::cin;

struct SinhVien
{
    std::string id;
    std::string ten;
    std::string lop;
    float diem1;
    float diem2;
    float diem3;
};

void nhap(SinhVien &A)
{
    std::cin >> A.id;
    std::cin.ignore();
    std::getline(std::cin, A.ten);
    std::cin >> A.lop;
    std::cin >> A.diem1;
    std::cin >> A.diem2;
    std::cin >> A.diem3;
}

bool cmp(const SinhVien &A, const SinhVien &B) { return A.id < B.id; }

void sap_xep(SinhVien *ds, const int n) { std::sort(ds, ds + n, cmp); }

void in_ds(const SinhVien *ds, const int n)
{
    for (int i = 0; i < n; i++)
        std::cout << i + 1 << ' '
                  << ds[i].id << ' '
                  << ds[i].ten << ' '
                  << ds[i].lop << ' '
                  << std::fixed << std::setprecision(1)
                  << ds[i].diem1 << ' '
                  << std::fixed << std::setprecision(1)
                  << ds[i].diem2 << ' '
                  << std::fixed << std::setprecision(1)
                  << ds[i].diem3 << '\n';
}

int main()
{
    int n;
    cin >> n;
    struct SinhVien *ds = new SinhVien[n];
    for (int i = 0; i < n; i++)
    {
        nhap(ds[i]);
    }
    sap_xep(ds, n);
    in_ds(ds, n);
    return 0;
}