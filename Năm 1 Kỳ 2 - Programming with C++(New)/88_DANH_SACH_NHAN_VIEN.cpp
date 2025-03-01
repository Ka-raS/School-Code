#include <bits/stdc++.h>
using namespace std;

struct NhanVien {
    string name, gender, birthday, address, code, date;
};

void nhap(NhanVien& a) {
    cin.ignore();
    getline(cin, a.name);

    cin >> a.gender >> a.birthday;
    cin.ignore();

    getline(cin, a.address);

    cin >> a.code >> a.date;
}

void inds(NhanVien* ds, int N) {
    for (int i = 0; i < N; i++) {
        cout << setfill('0') << setw(5) << i + 1 << ' ';

        cout << ds[i].name << ' ' << ds[i].gender << ' ' << ds[i].birthday <<
         ' ' << ds[i].address << ' ' << ds[i].code << ' ' << ds[i].date << '\n';
    }
}

int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    inds(ds,N);
    return 0;
}