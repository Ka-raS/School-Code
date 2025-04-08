#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    string name, code, date;
    double gpa;
};

void nhap(SinhVien& a) {
    getline(cin, a.name);
    cin >> a.code >> a.date >> a.gpa;
}

void in(SinhVien a) {
    cout << "B20DCCN001 " << a.name << ' ' << a.code << ' ';

    if (a.date[1] == '/')
        cout << 0;

    int i = 0;
    int n = a.date.size();

    while (i < n) {
        cout << a.date[i];
        i++;

        if (a.date[i - 1] == '/')
            break;

    }

    if (a.date[i + 1] == '/')
        cout << '0';

    while (i < n) {
        cout << a.date[i];
        i++;
    }
    
    cout << ' ' << fixed << setprecision(2) << a.gpa;
}

int main(){
    struct SinhVien a;
    nhap(a);
    in(a);
    return 0;
}