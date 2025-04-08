#include <iostream>
#include <string>

void swap(char &c)
{
    if (c == 'A')
        c = 'B';
    else
        c = 'A';
}

int countABAandBAB(std::string &str)
{
    int count = 0;
    const size_t n = str.length();
    for (size_t i = 0; i < n - 2; ++i)
    {
        const std::string subStr = str.substr(i, 3);
        if (subStr == "ABA" || subStr == "BAB")
        {
            ++count;
            swap(str[++i]);
        }
    }
    return count;
}

int countEndOfStr(std::string &str)
{
    int count = 0;
    if (str.substr(0, 2) == "BA")
    {
        ++count;
        swap(str.front());
    }
    if (str.substr(str.length() - 2, 2) == "AB")
    {
        ++count;
        swap(str.back());
    }
    return count;
}

int countMiddleOfStr(const std::string &str)
{
    int count = 0;
    const size_t n = str.length();
    for (size_t i = 1; i < n; ++i)
        if (str[i] != str[i - 1])
            ++count;
    return count;
}

int minSteps(std::string str)
{
    int count = 0;
    count += countABAandBAB(str);
    count += countEndOfStr(str);
    count += countMiddleOfStr(str);
    if (str.back() == 'B')
        ++count;
    return count;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::cout << minSteps(str) << std::endl;
    return 0;
}
