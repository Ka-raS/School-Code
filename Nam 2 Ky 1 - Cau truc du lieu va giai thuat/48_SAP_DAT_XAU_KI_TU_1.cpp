#include <iostream>

int isSortable(const std::string &str)
{
    int charCount[26] = {0};
    for (const char c : str)
        ++charCount[c - 'a'];

    const int max = str.length() / 2 + (str.length() % 2);
    for (const int count : charCount)
        if (count > max)
            return -1;
    return 1;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::string str;
        std::cin >> str;
        std::cout << isSortable(str) << std::endl;
    }
}