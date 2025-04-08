#include <iostream>

bool nextHAHA(std::string &str)
{
    const size_t n = str.size();

    if (str[n - 2] != 'H' && str[n - 3] != 'H')
    {
        str[n - 2] = 'H';
        return true;
    }

    size_t k = str.rfind('H');
    while (k >= 2 && str[k - 2] == 'H')
        k -= 2;
    if (k < 2)
        return false;

    str[k - 1] = 'H';
    while (k < n)
    {
        str[k] = 'A';
        ++k;
    }
    return true;
}

void printHAHAs(const size_t size)
{
    if (size == 2)
    {
        std::cout << "HA" << std::endl;
        return;
    }

    std::string str = 'H' + std::string(size - 1, 'A');
    do
    {
        std::cout << str << std::endl;
    } while (nextHAHA(str));
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        size_t size;
        std::cin >> size;
        printHAHAs(size);
    }
}