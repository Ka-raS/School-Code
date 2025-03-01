#include <iostream>

bool isValid(const std::string &str, const char upperbound)
{
    if (upperbound == 'D')
        return str.front() == 'A' || str.back() == 'A';

    if (str.front() == 'A' && str.back() == 'E')
        return true;
    if (str.front() == 'E' && str.back() == 'A')
        return true;

    const std::size_t i = str.find('A');

    if (i != 0 && str[i - 1] == 'E')
        return true;
    if (i != str.size() - 1 && str[i + 1] == 'E')
        return true;

    return false;
}

bool nextPermutation(std::string &str)
{
    int i = str.size() - 2;
    while (i >= 0 && str[i] > str[i + 1])
        --i;
    if (i < 0)
        return false;

    int j = str.size() - 1;
    while (str[j] < str[i])
        --j;

    std::swap(str[i], str[j]);

    int begin = i + 1;
    int end = str.size() - 1;
    while (begin < end)
    {
        std::swap(str[begin], str[end]);
        ++begin;
        --end;
    }
    return true;
}

void printPermutations(const char upperbound)
{
    std::string str;
    for (char c = 'A'; c <= upperbound; ++c)
        str.push_back(c);

    do
    {
        if (isValid(str, upperbound))
            std::cout << str << std::endl;
    } while (nextPermutation(str));
}

int main()
{
    char upperbound;
    std::cin >> upperbound;
    printPermutations(upperbound);
}