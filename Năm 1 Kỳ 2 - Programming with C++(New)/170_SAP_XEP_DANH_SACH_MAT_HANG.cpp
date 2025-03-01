#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct MatHang
{
private:
    int thu_tu;
    std::string ten_mat_hang;
    std::string nhom_hang;
    double gia_mua;
    double gia_ban;
    double loi_nhuan;

public:
    void dat_thu_tu(const int n)
    {
        thu_tu = n;
    }
    friend std::istream &operator>>(std::istream &input, MatHang &mat_hang)
    {
        std::getline(input, mat_hang.ten_mat_hang);
        std::getline(input, mat_hang.nhom_hang);
        input >> mat_hang.gia_mua >> mat_hang.gia_ban;
        input.ignore();
        mat_hang.loi_nhuan = mat_hang.gia_ban - mat_hang.gia_mua;

        return input;
    }
    friend std::ostream &operator<<(std::ostream &output, const MatHang &mat_hang)
    {
        output << mat_hang.thu_tu << ' '
               << mat_hang.ten_mat_hang << ' '
               << mat_hang.nhom_hang << ' '
               << std::fixed << std::setprecision(2)
               << mat_hang.loi_nhuan << '\n';
        return output;
    }
    double lay_loi_nhuan() const
    {
        return loi_nhuan;
    }
};

bool ham_sap_xep(const MatHang &mat_hang_1, const MatHang &mat_hang_2)
{
    return mat_hang_1.lay_loi_nhuan() > mat_hang_2.lay_loi_nhuan();
}

void input(std::vector<MatHang> &cac_mat_hang)
{
    for (int i = 0; i < cac_mat_hang.size(); i++)
    {
        MatHang &mat_hang = cac_mat_hang[i];
        mat_hang.dat_thu_tu(i + 1);
        std::cin >> mat_hang;
    }
}
void output(const std::vector<MatHang> &cac_mat_hang)
{
    for (const MatHang mat_hang : cac_mat_hang)
        std::cout << mat_hang;
}

int main()
{
    int so_mat_hang;
    std::cin >> so_mat_hang;
    std::cin.ignore();
    std::vector<MatHang> cac_mat_hang(so_mat_hang);

    input(cac_mat_hang);
    std::sort(cac_mat_hang.begin(), cac_mat_hang.end(), ham_sap_xep);
    output(cac_mat_hang);

    return 0;
}