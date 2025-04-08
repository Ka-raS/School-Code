#include <iostream>
#include <unordered_map>

const std::unordered_map<char, char> convert = {
    {'A', 'B'},
    {'B', 'A'},
};

bool nextString(std::string &str)
{
    size_t i = str.rfind('A');
    if (i == std::string::npos)
        return false;

    while (i < str.length())
    {
        str[i] = convert.at(str[i]);
        ++i;
    }

    return true;
}

void printABStrings(const size_t size)
{
    std::string str(size, 'A');
    do
    {
        std::cout << str << ' ';
    } while (nextString(str));
    std::cout << std::endl;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        size_t size;
        std::cin >> size;
        printABStrings(size);
    }
}