#include <bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    string name, code, birthday;
    double gpa;
public:
    void nhap() {
        getline(cin, name);
        cin >> code >> birthday >> gpa;
    }

    void xuat() {
        cout << "B20DCCN001 " << name << ' ' << code << ' ';

        if (birthday[1] == '/')
            cout << 0;

        int i = 0;
        int n = birthday.size();

        while (i < n) {
            cout << birthday[i];
            i++;

            if (birthday[i - 1] == '/')
                break;
        }

        if (birthday[i + 1] == '/')
            cout << '0';

        while (i < n) {
            cout << birthday[i];
            i++;
        }

        cout << ' ' << fixed << setprecision(2) << gpa;
    }
};

int main(){
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}