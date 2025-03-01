#include <bits/stdc++.h>
using namespace std;

struct NhanVien {
    string name, gender, birthday, address, code, date;
};

void nhap(NhanVien& a) {
    getline(cin, a.name);
    cin >> a.gender >> a.birthday;
    cin.ignore();
    getline(cin, a.address);
    cin >> a.code >> a.date;
}

void in(NhanVien a) {
    cout << "00001 " << a.name << ' ' << a.gender << ' ' << a.birthday << ' ' << a.address << ' ' << a.code << ' ' << a.date; 
}

int main(){
    struct NhanVien a;
    nhap(a);
    in(a);
    return 0;
}