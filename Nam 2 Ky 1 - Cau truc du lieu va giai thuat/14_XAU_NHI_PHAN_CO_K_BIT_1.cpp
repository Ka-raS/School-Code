#include <iostream>

void moveOnesToRight(std::string &str, int begin, int end)
{
    while (begin < end && str[end] == '0')
    {
        std::swap(str[begin], str[end]);
        ++begin;
        --end;
    }
}

bool nextBinary(std::string &str)
{
    size_t k = str.rfind('0', str.rfind('1')); // first '0' after a sequence of '1'
    if (k == std::string::npos)
        return false;

    std::swap(str[k], str[k + 1]); // swap '0' and '1'

    // begin is the second '1' of the '1' sequence from left to right
    moveOnesToRight(str, k + 2, str.size() - 1);
    return true;
}

void printBinaries(const size_t size, const int ones)
{
    std::string str = std::string(size - ones, '0') + std::string(ones, '1');
    do
    {
        std::cout << str << std::endl;
    } while (nextBinary(str));
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        size_t size;
        int ones;
        std::cin >> size >> ones;
        printBinaries(size, ones);
    }
}