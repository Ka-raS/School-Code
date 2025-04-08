#include <bits/stdc++.h>

void print(const std::string &s)
{
    int sum = 0;
    std::multiset<char> set;

    for (const char &c : s)
    {
        if (c < '0' || c > '9')
            set.insert(c);
        else
            sum += c - '0';
    }

    for (const char &c : set)
        std::cout << c;
    std::cout << sum << '\n';
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string s;
        std::cin >> s;
        print(s);
    }

    return 0;
}