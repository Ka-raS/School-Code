#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using std::cin;

struct NhanVien
{
public:
    struct Ngay
    {
        int ngay;
        int thang;
        int nam;

        friend std::istream &operator>>(std::istream &input, Ngay &A)
        {
            std::string ngay_str;
            std::getline(input, ngay_str);
            std::string so;
            size_t i = 0;

            while (ngay_str[i] != '/')
                so.push_back(ngay_str[i++]);
            A.ngay = std::stoi(so);
            so.clear();
            i++;

            while (ngay_str[i] != '/')
                so.push_back(ngay_str[i++]);
            A.thang = std::stoi(so);
            so.clear();
            i++;

            while (ngay_str[i] != '/')
                so.push_back(ngay_str[i++]);
            A.nam = std::stoi(so);
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

    int thu_tu;
    std::string ten;
    std::string gioi_tinh;
    Ngay ngay_sinh;
    std::string dia_chi;
    std::string ma_so_thue;
    Ngay ngay_ky_hop_dong;
};

int thu_tu = 1;
void nhap(NhanVien &A)
{
    if (thu_tu == 1)
        std::cin.ignore();
    A.thu_tu = thu_tu++;
    std::getline(std::cin, A.ten);
    std::getline(std::cin, A.gioi_tinh);
    std::cin >> A.ngay_sinh;
    std::getline(std::cin, A.dia_chi);
    std::getline(std::cin, A.ma_so_thue);
    std::cin >> A.ngay_ky_hop_dong;
}

bool cmp(const NhanVien &A, const NhanVien &B)
{
    if (A.ngay_sinh.nam != B.ngay_sinh.nam)
        return A.ngay_sinh.nam < B.ngay_sinh.nam;
    if (A.ngay_sinh.ngay != B.ngay_sinh.ngay)
        return A.ngay_sinh.ngay < B.ngay_sinh.ngay;
    return A.ngay_sinh.thang < B.ngay_sinh.thang;
}

void sapxep(NhanVien *ds, const int N)
{
    std::sort(ds, ds + N, cmp);
}

void inds(const NhanVien *ds, const int N)
{
    for (size_t i = 0; i < N; i++)
        std::cout << std::setw(5) << std::setfill('0')
                  << ds[i].thu_tu << ' '
                  << ds[i].ten << ' '
                  << ds[i].gioi_tinh << ' '
                  << ds[i].ngay_sinh << ' '
                  << ds[i].dia_chi << ' '
                  << ds[i].ma_so_thue << ' '
                  << ds[i].ngay_ky_hop_dong << '\n';
}

int main()
{
    struct NhanVien ds[50];
    int N, i;
    cin >> N;
    for (i = 0; i < N; i++)
        nhap(ds[i]);
    sapxep(ds, N);
    inds(ds, N);
    return 0;
}