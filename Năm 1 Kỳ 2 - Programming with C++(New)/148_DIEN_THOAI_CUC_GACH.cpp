#include <bits/stdc++.h>

std::unordered_map<char, int> m = {
    {'A', 2},
    {'B', 2},
    {'C', 2},
    {'D', 3},
    {'E', 3},
    {'F', 3},
    {'G', 4},
    {'H', 4},
    {'I', 4},
    {'J', 5},
    {'K', 5},
    {'L', 5},
    {'M', 6},
    {'N', 6},
    {'O', 6},
    {'P', 7},
    {'Q', 7},
    {'R', 7},
    {'S', 7},
    {'T', 8},
    {'U', 8},
    {'V', 8},
    {'W', 9},
    {'X', 9},
    {'Y', 9},
    {'Z', 9},
};

bool check(const std::string &s)
{
    const size_t n = s.size();
    for (size_t i = 0; i < n / 2; i++)
    {
        int val_first = m[std::toupper(s[i])];
        int val_last = m[std::toupper(s[n - i - 1])];
        if (val_first != val_last)
            return false;
    }
    return true;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::string s;
        std::cin >> s;
        if (check(s))
            std::cout << "YES" << '\n';
        else
            std::cout << "NO" << '\n';
    }

    return 0;
}