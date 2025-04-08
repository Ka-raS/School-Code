#include <iostream>

int isSortable(const std::string &str, const int distance)
{
    int charCount[26] = {0};
    for (const char c : str)
        ++charCount[c - 'A'];

    const int max = str.length() / distance + (str.length() % distance != 0);
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
        int distance;
        std::string str;
        std::cin >> distance >> str;
        std::cout << isSortable(str, distance) << std::endl;
    }
}