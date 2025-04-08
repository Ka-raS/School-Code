#include <bits/stdc++.h>

struct SinhVien {
    std::string name, code, date;
    float gpa; 
};

void standardizeDate(std::string& date) {
    if (date[1] == '/')
        date.insert(0, "0");
    if (date[4] == '/')
        date.insert(3, "0");
}

void nhapThongTinSV(SinhVien& a) {
    std::getline(std::cin, a.name);
    std::cin >> a.code >> a.date >> a.gpa;

    standardizeDate(a.date);
}

void inThongTinSV(const SinhVien a) {
    std::cout << "N20DCCN001 " << a.name << ' ' << a.code << ' ' << a.date << ' ';
    std::cout << std::setprecision(2) << std::fixed << a.gpa;
}

int main(){
    struct SinhVien a;
    nhapThongTinSV(a);
    inThongTinSV(a);
    return 0;
}