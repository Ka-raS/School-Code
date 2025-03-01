#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

const size_t UNDEFINED = std::numeric_limits<size_t>::max();

size_t findMin(const std::unordered_map<char, size_t> &map)
{
    size_t result = UNDEFINED;
    for (const std::pair<char, int> &pair : map)
        if (result > pair.second)
            result = pair.second;
    return result;
}

size_t smallestSubStr(const std::string &str)
{
    std::unordered_map<char, size_t> map;
    for (const char &c : str)
        map[c] = UNDEFINED;

    size_t charCount = 0;
    size_t i = 0;
    while (i < str.size())
    {
        if (map[str[i]] == UNDEFINED)
            ++charCount;
        map[str[i]] = i;
        if (charCount == map.size())
            break;
        ++i;
    }

    size_t begin = findMin(map);
    size_t length = i - begin + 1;
    if (length == map.size())
        return length;

    char minChar = str[begin];
    while (i < str.size())
    {
        map[str[i]] = i;
        if (str[i] == minChar)
        {
            begin = findMin(map);
            minChar = str[begin];
        }
        if (length > i - begin + 1)
        {
            length = i - begin + 1;
            if (length == map.size())
                return length;
        }
        ++i;
    }

    return length;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        std::string str;
        std::cin >> str;
        std::cout << smallestSubStr(str) << std::endl;
    }

    return 0;
}
