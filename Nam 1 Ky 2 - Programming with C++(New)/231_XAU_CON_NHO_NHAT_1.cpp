#include <iostream>
#include <string>
#include <vector>

std::vector<int> convert(const std::string &keyword)
{
    std::vector<int> map(256, 0);
    for (const char &c : keyword)
        ++map[c];
    return map;
}

std::string smallestSubStr(const std::string &str, const std::string &keyword)
{
    const std::vector<int> mapBase = convert(keyword);

    size_t begin;
    size_t length = str.size() + 1;

    const size_t end = str.size() - keyword.size() + 1;
    for (size_t i = 0; i < end; ++i)
        if (mapBase[str[i]] > 0)
        {
            const size_t currentBegin = i;
            int charCounts = keyword.size();
            std::vector<int> map = mapBase;

            for (size_t j = i; j < str.size(); ++j)
                if (map[str[j]] > 0)
                {
                    --map[str[j]];
                    --charCounts;
                    if (charCounts == 0)
                    {
                        const size_t currentLength = j - currentBegin + 1;
                        if (length > currentLength)
                        {
                            begin = currentBegin;
                            length = currentLength;
                        }
                        break;
                    }
                }
        }

    if (length == str.size() + 1)
        return "-1";
    return str.substr(begin, length);
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        std::string str, keyword;
        std::cin >> str >> keyword;
        std::cout << smallestSubStr(str, keyword) << std::endl;
    }

    return 0;
}