#include <bits/stdc++.h>

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string str;
        std::cin >> str;

        int sum = 0;
        for (char c : str)
            if ('0' <= c && c <= '9')
                sum += c - 48;
        std::cout << sum << '\n';
    }

    return 0;
}