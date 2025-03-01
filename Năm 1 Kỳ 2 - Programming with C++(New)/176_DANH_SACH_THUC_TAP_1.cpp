#include <bits/stdc++.h>

struct SinhVien
{
    int thu_tu;
    std::string msv, ho_va_ten, lop, email, doanh_nghiep;
};

void nhapSV(SinhVien &SV)
{
    std::cin >> SV.msv;
    std::cin.ignore();
    std::getline(std::cin, SV.ho_va_ten);
    std::cin >> SV.lop >> SV.email >> SV.doanh_nghiep;
}

void xuatSV(const SinhVien &SV)
{
    std::cout << SV.thu_tu << ' '
              << SV.msv << ' '
              << SV.ho_va_ten << ' '
              << SV.lop << ' '
              << SV.email << ' '
              << SV.doanh_nghiep << '\n';
}

bool sap_xep_bang_chu_cai(const SinhVien &a, const SinhVien &b)
{
    return a.ho_va_ten < b.ho_va_ten;
}

void xuat_bo_loc(const std::vector<SinhVien> &SV, const std::string &doanh_nghiep)
{
    for (SinhVien tungSV : SV)
        if (tungSV.doanh_nghiep == doanh_nghiep)
            xuatSV(tungSV);
}

int main()
{
    int so_luong;
    std::cin >> so_luong;
    std::vector<SinhVien> SV(so_luong);

    for (size_t i = 0; i < so_luong; i++)
    {
        SV[i].thu_tu = i + 1;
        nhapSV(SV[i]);
    }

    std::sort(SV.begin(), SV.end(), sap_xep_bang_chu_cai);
    int so_lan_loc;
    std::cin >> so_lan_loc;
    std::string doanh_nghiep;

    while (so_lan_loc--)
    {
        std::cin >> doanh_nghiep;
        xuat_bo_loc(SV, doanh_nghiep);
    }

    return 0;
}