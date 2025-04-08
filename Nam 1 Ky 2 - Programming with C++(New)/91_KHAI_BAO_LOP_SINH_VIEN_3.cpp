#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
    int ngay;
    int thang;
    int nam;

public:
    friend istream &operator>>(istream &input, Date &date)
    {
        string tmp;
        getline(input, tmp, '/');
        date.ngay = stoi(tmp);
        getline(input, tmp, '/');
        date.thang = stoi(tmp);
        getline(input, tmp);
        date.nam = stoi(tmp);
        return input;
    }

    friend ostream &operator<<(ostream &output, const Date &date)
    {
        output << setw(2) << setfill('0')
               << date.ngay << '/'
               << setw(2) << setfill('0')
               << date.thang << '/'
               << setw(4) << setfill('0')
               << date.nam;
        return output;
    }
};

class SinhVien
{
private:
    string id_lop;
    Date ngay_sinh;
    string ten;
    double gpa;

    void chuanHoaTen()
    {
        string tu;
        istringstream ss(ten);
        ten.clear();

        while (ss >> tu)
        {
            for (char &chuCai : tu)
                chuCai = tolower(chuCai);
            tu[0] = toupper(tu[0]);
            ten += tu + ' ';
        }
        ten.pop_back();
    }

public:
    friend istream &operator>>(istream &input, SinhVien &sinh_vien)
    {
        getline(input >> ws, sinh_vien.ten);
        getline(input >> ws, sinh_vien.id_lop);
        input >> sinh_vien.ngay_sinh;
        input >> sinh_vien.gpa;

        sinh_vien.chuanHoaTen();
        return input;
    }

    friend ostream &operator<<(ostream &output, const SinhVien &sinh_vien)
    {
        output << "B20DCCN001 "
               << sinh_vien.ten << ' '
               << sinh_vien.id_lop << ' '
               << sinh_vien.ngay_sinh << ' '
               << fixed << setprecision(2)
               << sinh_vien.gpa;

        return output;
    }
};

int main()
{
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}