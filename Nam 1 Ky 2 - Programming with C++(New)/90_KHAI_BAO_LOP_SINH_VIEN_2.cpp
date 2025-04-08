#include <bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    string name, code, date;
    double gpa;

public:
    friend istream& operator >> (istream& input, SinhVien& a) {
        getline(input, a.name);
        input >> a.code >> a.date >> a.gpa;
        
        return input;
    }

    friend ostream& operator<<(ostream& output, const SinhVien a) {
        output << "B20DCCN001 " << a.name << ' ' << a.code << ' ';
        
        if (a.date[1] == '/')
            output << 0;

        int i = 0;
        int n = a.date.size();

        while (i < n) {
            output << a.date[i];
            i++;

            if (a.date[i - 1] == '/')
                break;
        }

        if (a.date[i + 1] == '/')
            output << '0';

        while (i < n) {
            output << a.date[i];
            i++;
        }

        output << ' ' << fixed << setprecision(2) << a.gpa;

        return output;
    }
};

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}