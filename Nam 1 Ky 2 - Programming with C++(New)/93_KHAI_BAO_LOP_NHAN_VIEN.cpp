#include <bits/stdc++.h>
using namespace std;

void standardizeDate(string& date) {
    if (date[1] == '/')
        date.insert(0, "0");
    if (date[4] == '/')
        date.insert(3, "0");
}

class NhanVien {
    private:
        string name, gender, bday, address, code, date;
    
    public:
        friend istream& operator >> (istream& input, NhanVien& a) {
            getline(input, a.name);
            input >> a.gender >> a.bday;
            input.ignore();
            getline(input, a.address);
            input >> a.code >> a.date;
            standardizeDate(a.bday);
            standardizeDate(a.date);
            return input;
        }

        friend ostream& operator >> (ostream& output, const NhanVien a) {
            output << "00001 " << a.name << ' ' << a.gender << ' ' << a.bday
            << ' ' << a.address << ' ' << a.code << ' ' << a.date;
            return output;
        }
};

int main(){
    NhanVien a;
    cin >> a;
    cout >> a;
    return 0;
}