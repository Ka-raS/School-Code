#include <bits/stdc++.h>

std::map<char, int> convert_map(const std::string &str)
{
    std::map<char, int> letter_map;
    for (char letter : str)
        letter_map[letter]++;
    return letter_map;
}

bool is_interleaved(const std::map<char, int> &letter_map, const int size)
{
    const int max = ceil((double)size / 2);
    for (const auto &pair : letter_map)
        if (pair.second > max)
            return false;
    return true;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string str;
        std::cin >> str;

        std::map<char, int> letter_map = convert_map(str);
        int size = str.size();
        std::cout << is_interleaved(letter_map, size) << '\n';
    }

    return 0;
}