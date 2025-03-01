#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using std::cin;
using std::cout;

int id_num = 0;
struct SinhVien
{
private:
    struct Ngay
    {
        int ngay;
        int thang;
        int nam;

        friend std::istream &operator>>(std::istream &input, Ngay &A)
        {
            std::string ngay_str;
            std::getline(input, ngay_str);
            std::stringstream ngay_ss(ngay_str);

            std::getline(ngay_ss, ngay_str, '/');
            A.ngay = std::stoi(ngay_str);
            std::getline(ngay_ss, ngay_str, '/');
            A.thang = std::stoi(ngay_str);
            std::getline(ngay_ss, ngay_str);
            A.nam = std::stoi(ngay_str);

            return input;
        }

        friend std::ostream &operator<<(std::ostream &output, const Ngay &A)
        {
            output << std::setw(2) << std::setfill('0')
                   << A.ngay << '/'
                   << std::setw(2) << std::setfill('0')
                   << A.thang << '/'
                   << std::setw(4) << std::setfill('0')
                   << A.nam;

            return output;
        }
    };

    std::string id;
    std::string ten;
    std::string lop;
    Ngay ngay_sinh;
    float gpa;

    void set_id(const int n)
    {
        std::ostringstream id_oss;
        id_oss << "B20DCCN" << std::setw(3) << std::setfill('0') << id_num;
        id = id_oss.str();
    }

    void chuan_hoa_ten()
    {
        std::string ten_moi;
        std::string buf;
        std::stringstream ten_ss(ten);

        while (ten_ss >> buf)
        {
            for (char &c : buf)
                c = std::tolower(c);
            buf[0] = std::toupper(buf[0]);
            ten_moi += buf + ' ';
        }
        ten_moi.erase(ten_moi.size() - 1);
        ten = ten_moi;
    }

public:
    const float get_gpa() const { return gpa; }

    friend std::istream &operator>>(std::istream &input, SinhVien &A)
    {
        scanf("\n\n");
        A.set_id(++id_num);
        std::getline(input, A.ten);
        scanf("\n");
        A.chuan_hoa_ten();
        std::getline(input, A.lop);
        input >> A.ngay_sinh;
        input >> A.gpa;

        return input;
    }
    friend std::ostream &operator<<(std::ostream &output, const SinhVien &A)
    {
        output << A.id << ' '
               << A.ten << ' '
               << A.lop << ' '
               << A.ngay_sinh << ' '
               << std::fixed << std::setprecision(2)
               << A.gpa << '\n';

        return output;
    }
};

bool cmp(const SinhVien &A, const SinhVien &B) { return A.get_gpa() > B.get_gpa(); }

void sapxep(SinhVien *ds, const int N) { std::sort(ds, ds + N, cmp); }

int main()
{
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> ds[i];
    }
    sapxep(ds, N);
    for (i = 0; i < N; i++)
    {
        cout << ds[i];
    }
    return 0;
}