#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using std::cin;
using std::cout;

int id_num = 0;
class NhanVien
{
private:
    class Ngay
    {
    private:
        int thang;
        int ngay;
        int nam;

    public:
        friend std::istream &operator>>(std::istream &input, Ngay &date)
        {
            std::string buf;
            std::getline(input, buf, '/');
            date.thang = std::stoi(buf);
            std::getline(input, buf, '/');
            date.ngay = std::stoi(buf);
            std::getline(input, buf);
            date.nam = std::stoi(buf);
            return input;
        }

        friend std::ostream &operator<<(std::ostream &output, const Ngay &date)
        {
            output << std::setw(2) << std::setfill('0')
                   << date.thang << '/'
                   << std::setw(2) << std::setfill('0')
                   << date.ngay << '/'
                   << std::setw(4) << std::setfill('0')
                   << date.nam;
            return output;
        }
    };

private:
    int id;
    std::string ten;
    Ngay ngay_sinh;
    std::string gioi_tinh;
    std::string dia_chi;
    std::string ma_so_thue;
    Ngay ngay_ky_hop_dong;

private:
    void chuan_hoa_ten()
    {
        std::string buf;
        std::string ten_moi;
        std::stringstream ten_sstream(ten);

        while (ten_sstream >> buf)
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
    friend std::istream &operator>>(std::istream &input, NhanVien &nhan_vien)
    {
        if (id_num == 0)
            input.ignore();
        nhan_vien.id = ++id_num;
        std::getline(input, nhan_vien.ten);
        nhan_vien.chuan_hoa_ten();
        std::getline(input, nhan_vien.gioi_tinh);
        input >> nhan_vien.ngay_sinh;
        std::getline(input, nhan_vien.dia_chi);
        std::getline(input, nhan_vien.ma_so_thue);
        input >> nhan_vien.ngay_ky_hop_dong;

        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const NhanVien &nhan_vien)
    {
        output << std::setw(5) << std::setfill('0')
               << nhan_vien.id << ' '
               << nhan_vien.ten << ' '
               << nhan_vien.gioi_tinh << ' '
               << nhan_vien.ngay_sinh << ' '
               << nhan_vien.dia_chi << ' '
               << nhan_vien.ma_so_thue << ' '
               << nhan_vien.ngay_ky_hop_dong << '\n';
        return output;
    }
};

int main()
{
    NhanVien ds[50];
    int N, i;
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> ds[i];
    for (i = 0; i < N; i++)
        cout << ds[i];
    return 0;
}