#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <algorithm>
using std::cin;
using std::cout;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    friend std::istream &operator>>(std::istream &input, Date &date)
    {
        std::string buf;
        std::getline(input >> std::ws, buf, '/');
        date.day = std::stoi(buf);
        std::getline(input >> std::ws, buf, '/');
        date.month = std::stoi(buf);
        std::getline(input >> std::ws, buf);
        date.year = std::stoi(buf);
        return input;
    }
};

int customerOrdinalNumber = 0;
class KhachHang
{
    friend class HoaDon;

private:
    std::string ID;
    std::string fullName;
    std::string gender;
    Date birthDate;
    std::string address;

    void setID(const int number)
    {
        std::ostringstream ossID;
        ossID << "KH" << std::setw(3) << std::setfill('0') << number;
        this->ID = ossID.str();
    }
    void standardizeName()
    {
        std::string buf;
        std::istringstream issFullName(fullName);
        fullName.clear();

        while (issFullName >> buf)
        {
            for (char &c : buf)
                c = std::tolower(c);
            buf[0] = std::toupper(buf[0]);
            fullName += buf + ' ';
        }

        fullName.pop_back();
    }

public:
    const std::string &getFullName() const { return fullName; }
    const std::string &getAddress() const { return address; }
    friend std::istream &operator>>(std::istream &input, KhachHang &customer);
};

std::unordered_map<std::string, KhachHang> customerMap;
std::istream &operator>>(std::istream &input, KhachHang &customer)
{
    customer.setID(++customerOrdinalNumber);
    std::getline(input >> std::ws, customer.fullName);
    customer.standardizeName();
    std::getline(input >> std::ws, customer.gender);
    input >> customer.birthDate;
    std::getline(input >> std::ws, customer.address);

    customerMap[customer.ID] = customer;
    return input;
}

int productOrdinalNumber = 0;
class MatHang
{
    friend class HoaDon;

private:
    std::string ID;
    std::string name;
    std::string specifier;
    int purchasePrice;
    int sellingPrice;
    int profit;

    void calculateProfit() { profit = sellingPrice - purchasePrice; }
    void setID(const int number)
    {
        std::ostringstream ossID;
        ossID << "MH" << std::setw(3) << std::setfill('0') << number;
        this->ID = ossID.str();
    }

public:
    const std::string &getName() const { return name; }
    friend std::istream &operator>>(std::istream &input, MatHang &product);
};

std::unordered_map<std::string, MatHang> productMap;
std::istream &operator>>(std::istream &input, MatHang &product)
{
    product.setID(++productOrdinalNumber);
    std::getline(input >> std::ws, product.name);
    std::getline(input >> std::ws, product.specifier);
    input >> product.purchasePrice;
    input >> product.sellingPrice;

    product.calculateProfit();
    productMap[product.ID] = product;
    return input;
}

int receiptOrdinalNumber = 0;
class HoaDon
{
private:
    std::string ID;
    std::string customerID;
    std::string profuctID;
    KhachHang customer;
    MatHang product;
    int quantity;
    long long bill;
    long long profit;

    void setID(const int number)
    {
        std::ostringstream ossID;
        ossID << "HD" << std::setw(3) << std::setfill('0') << number;
        this->ID = ossID.str();
    }
    void findCustomer() { customer = customerMap[customerID]; }
    void findProduct() { product = productMap[profuctID]; }
    void calculateBill()
    {
        bill = quantity;
        bill *= product.sellingPrice;
    }
    void calculateProfit() { profit = quantity * product.profit; }

public:
    long long getProfit() const { return profit; }
    const std::string &getProductName() const { return product.getName(); }
    friend std::istream &operator>>(std::istream &input, HoaDon &receipt)
    {
        receipt.setID(++receiptOrdinalNumber);
        input >> receipt.customerID >> receipt.profuctID >> receipt.quantity;

        receipt.findCustomer();
        receipt.findProduct();
        receipt.calculateBill();
        receipt.calculateProfit();
        return input;
    }
    friend std::ostream &operator<<(std::ostream &output, const HoaDon &receipt)
    {
        output << receipt.ID << ' '
               << receipt.customer.getFullName() << ' '
               << receipt.customer.getAddress() << ' '
               << receipt.product.getName() << ' '
               << receipt.quantity << ' '
               << receipt.bill << ' '
               << receipt.profit << '\n';
        return output;
    }
};

void sapxep(HoaDon *receiptList, const int numberOfReceipts)
{
    auto compareFuction = [](const HoaDon &receiptA, const HoaDon &receiptB)
    {
        const long long receiptAProfit = receiptA.getProfit(),
                        receiptBProfit = receiptB.getProfit();
        const std::string &receiptAProductName = receiptA.getProductName(),
                          &receiptBProductName = receiptB.getProductName();

        if (receiptAProfit == receiptBProfit)
            return receiptAProductName > receiptBProductName;
        return receiptAProfit > receiptBProfit;
    };

    std::sort(receiptList, receiptList + numberOfReceipts, compareFuction);
}

int main()
{
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N, M, K, i;
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> dskh[i];
    cin >> M;
    for (i = 0; i < M; i++)
        cin >> dsmh[i];
    cin >> K;
    for (i = 0; i < K; i++)
        cin >> dshd[i];

    sapxep(dshd, K);

    for (i = 0; i < K; i++)
        cout << dshd[i];
    return 0;
}