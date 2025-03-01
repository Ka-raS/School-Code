#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iomanip>

class Receipt;
class Date
{
    friend class Receipt;

private:
    int day;
    int month;
    int year;

public:
    friend std::istream &operator>>(std::istream &input, Date date)
    {
        std::string dayStr, monthStr, yearStr;
        std::getline(input >> std::ws, dayStr, '/');
        std::getline(input >> std::ws, monthStr, '/');
        std::getline(input >> std::ws, yearStr);

        date.day = std::stoi(dayStr);
        date.month = std::stoi(monthStr);
        date.month = std::stoi(yearStr);
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Date &date)
    {
        output << std::setw(2) << std::setfill('0')
               << date.day << '/'
               << std::setw(2) << std::setfill('0')
               << date.month << '/'
               << std::setw(4) << std::setfill('0')
               << date.year;
        return output;
    }
};

class Customer
{
    friend class Receipt;

private:
    std::string ID;
    std::string fullName;
    std::string gender;
    Date birthDate;
    std::string address;

public:
    const std::string &getID() const { return this->ID; }
    void setID(const int n)
    {
        std::stringstream IDStrStream;
        IDStrStream << "KH" << std::setw(3) << std::setfill('0') << n;
        this->ID = IDStrStream.str();
    }

    friend std::istream &operator>>(std::istream &input, Customer &customer)
    {
        std::getline(input >> std::ws, customer.fullName);
        std::getline(input >> std::ws, customer.gender);
        input >> customer.birthDate;
        std::getline(input >> std::ws, customer.address);
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Receipt &receipt);
};

class Product
{
    friend class Receipt;

private:
    std::string ID;
    std::string name;
    std::string specifier;
    int purchasedPrice;
    int sellingPrice;

public:
    const std::string &getID() const { return this->ID; }
    void setID(const int n)
    {
        std::stringstream IDStrStream;
        IDStrStream << "MH" << std::setw(3) << std::setfill('0') << n;
        this->ID = IDStrStream.str();
    }

    friend std::istream &operator>>(std::istream &input, Product &product)
    {
        std::getline(input >> std::ws, product.name);
        std::getline(input >> std::ws, product.specifier);
        input >> product.purchasedPrice;
        input >> product.sellingPrice;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Receipt &receipt);
};

class Receipt
{
private:
    std::string ID;
    std::string customerID;
    std::string productID;
    int quantity;

    Customer customer;
    Product product;

    long long bill() const
    {
        long long bill = this->quantity;
        bill *= this->product.sellingPrice;
        return bill;
    }

public:
    const std::string &getID() const { return this->ID; }
    void setID(const int n)
    {
        std::stringstream IDStrStream;
        IDStrStream << "HD" << std::setw(3) << std::setfill('0') << n;
        this->ID = IDStrStream.str();
    }

    void fillInCustomer(const std::unordered_map<std::string, Customer> &customerMap)
    {
        this->customer = customerMap.at(customerID);
    }

    void fillInProduct(const std::unordered_map<std::string, Product> &productMap)
    {
        this->product = productMap.at(productID);
    }

    friend std::istream &operator>>(std::istream &input, Receipt &receipt)
    {
        input >> receipt.customerID;
        input >> receipt.productID;
        input >> receipt.quantity;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Receipt &receipt)
    {
        output << receipt.ID << ' '
               << receipt.customer.fullName << ' '
               << receipt.customer.address << ' '
               << receipt.product.name << ' '
               << receipt.product.specifier << ' '
               << receipt.product.purchasedPrice << ' '
               << receipt.product.sellingPrice << ' '
               << receipt.quantity << ' '
               << receipt.bill();
        return output;
    }
};

template <typename Typename>
std::vector<Typename> inputListFromFile(const char *fileName)
{
    std::vector<Typename> List;
    std::fstream inputFile(fileName);

    int numberOfItems;
    inputFile >> numberOfItems;
    List.resize(numberOfItems);

    int ordinalNumber = 0;
    for (Typename &item : List)
    {
        inputFile >> item;
        item.setID(++ordinalNumber);
    }

    inputFile.close();
    return List;
}

template <typename Typename>
std::unordered_map<std::string, Typename> convertMap(const std::vector<Typename> &List)
{
    std::unordered_map<std::string, Typename> Map;
    for (const Typename &item : List)
        Map[item.getID()] = item;
    return Map;
}

void fillInReceiptList(std::vector<Receipt> &receiptList,
                       const std::unordered_map<std::string, Customer> &customerMap,
                       const std::unordered_map<std::string, Product> &productMap)
{
    for (Receipt &receipt : receiptList)
    {
        receipt.fillInCustomer(customerMap);
        receipt.fillInProduct(productMap);
    }
}

template <typename Typename>
void outputList(const std::vector<Typename> &List)
{
    for (const Typename &item : List)
        std::cout << item << std::endl;
}

int main()
{
    std::vector<Customer> customerList = inputListFromFile<Customer>("KH.in");
    std::vector<Product> productList = inputListFromFile<Product>("MH.in");
    std::vector<Receipt> receiptList = inputListFromFile<Receipt>("HD.in");

    std::unordered_map<std::string, Customer> customerMap = convertMap(customerList);
    std::unordered_map<std::string, Product> productMap = convertMap(productList);

    fillInReceiptList(receiptList, customerMap, productMap);
    outputList(receiptList);

    return 0;
}