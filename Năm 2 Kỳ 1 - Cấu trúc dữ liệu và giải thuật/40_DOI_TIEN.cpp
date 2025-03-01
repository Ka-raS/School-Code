#include <iostream>
#include <set>

const std::set<int> billsDenominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int minBillsConvert(int moneyAmount)
{
    int billsCount = 0;

    while (moneyAmount > 0)
    {
        auto bill = billsDenominations.upper_bound(moneyAmount);
        --bill;
        moneyAmount -= *bill;
        ++billsCount;
    }

    return billsCount;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        int moneyAmount;
        std::cin >> moneyAmount;
        std::cout << minBillsConvert(moneyAmount) << std::endl;
    }
}