#include <iostream>

std::string previousBinary(std::string str)
{
    const size_t n = str.size();
    size_t i = str.rfind('1');
    if (i == std::string::npos)
        return std::string(n, '1');

    str[i] = '0';
    while (++i < n)
        str[i] = '1';
    return str;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::string binary;
        std::cin >> binary;
        std::cout << previousBinary(binary) << std::endl;
    }
}