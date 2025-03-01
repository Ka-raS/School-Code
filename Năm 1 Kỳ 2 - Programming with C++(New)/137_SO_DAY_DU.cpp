#include <bits/stdc++.h>

int check_completeness(const std::string &num)
{
    if (num[0] <= '0')
        return -1;

    std::set<int> digit_set;
    for (char digit : num)
    {
        if (digit < '0' || digit > '9')
            return -1;
        digit_set.insert(digit);
        if (digit_set.size() == 10)
            return 1;
    }
    return 0;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string num;
        std::cin >> num;

        int ans = check_completeness(num);
        switch (ans)
        {
        case -1:
            std::cout << "INVALID";
            break;
        case 0:
            std::cout << "NO";
            break;
        case 1:
            std::cout << "YES";
            break;
        default:
            break;
        }
        std::cout << '\n';
    }

    return 0;
}