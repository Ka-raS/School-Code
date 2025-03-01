#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using std::cin;

struct SinhVien
{
private:
    struct Ngay
    {
    private:
        int ngay;
        int thang;
        int nam;

    public:
        void dat_ngay_sinh(const std::string &str_tmp)
        {
            size_t i = 0;
            std::string so;

            while (str_tmp[i] != '/')
                so.push_back(str_tmp[i++]);
            ngay = std::stoi(so);
            so.clear();
            i++;

            while (str_tmp[i] != '/')
                so.push_back(str_tmp[i++]);
            thang = std::stoi(so);
            so.clear();
            i++;

            while (i < str_tmp.size())
                so.push_back(str_tmp[i++]);
            nam = std::stoi(so);
        }

    public:
        int lay_ngay() const
        {
            return ngay;
        }
        int lay_thang() const
        {
            return thang;
        }
        int lay_nam() const
        {
            return nam;
        }
    };

private:
    std::string id;
    std::string ten;
    std::string lop;
    Ngay ngay_sinh;
    float gpa;

public:
    void dat_id(const int n)
    {
        std::ostringstream id_string;
        id_string << "B20DCCN"
                  << std::setw(3) << std::setfill('0')
                  << n;
        id = id_string.str();
    }
    void dat_ten(const std::string &str_tmp)
    {
        std::stringstream str_tmp_stream(str_tmp);
        std::string tu;

        while (str_tmp_stream >> tu)
        {
            for (char &chu : tu)
                chu = std::tolower(chu);
            tu.front() = std::toupper(tu.front());
            ten += tu + ' ';
        }
        ten.erase(ten.size() - 1);
    }
    void dat_lop(const std::string &str_tmp)
    {
        lop = str_tmp;
    }
    void dat_ngay_sinh(const std::string str_tmp)
    {
        ngay_sinh.dat_ngay_sinh(str_tmp);
    }
    void dat_gpa(const float n)
    {
        gpa = n;
    }

public:
    std::string lay_id() const
    {
        return id;
    }
    std::string lay_ten() const
    {
        return ten;
    }
    std::string lay_lop() const
    {
        return lop;
    }
    std::string lay_ngay_sinh() const
    {
        std::ostringstream ngay;
        ngay << std::setw(2) << std::setfill('0')
             << ngay_sinh.lay_ngay() << '/'
             << std::setw(2) << std::setfill('0')
             << ngay_sinh.lay_thang() << '/'
             << std::setw(4) << std::setfill('0')
             << ngay_sinh.lay_nam();
        return ngay.str();
    }
    std::string lay_gpa() const
    {
        std::ostringstream gpa_string;
        gpa_string << std::fixed << std::setprecision(2)
                   << gpa;
        return gpa_string.str();
    }
};

void nhap(SinhVien *ds, const int N)
{
    std::cin.ignore();
    for (int i = 0; i < N; i++)
    {
        ds[i].dat_id(i + 1);
        std::string str_tmp;

        std::getline(std::cin, str_tmp);
        ds[i].dat_ten(str_tmp);

        std::getline(std::cin, str_tmp);
        ds[i].dat_lop(str_tmp);

        std::getline(std::cin, str_tmp);
        ds[i].dat_ngay_sinh(str_tmp);

        float gpa;
        std::cin >> gpa;
        ds[i].dat_gpa(gpa);
        std::cin.ignore();
    }
}

void in(const SinhVien *ds, const int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << ds[i].lay_id() << ' '
                  << ds[i].lay_ten() << ' '
                  << ds[i].lay_lop() << ' '
                  << ds[i].lay_ngay_sinh() << ' '
                  << ds[i].lay_gpa() << '\n';
    }
}

int main()
{
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    in(ds, N);
    return 0;
}