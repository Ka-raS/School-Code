#include <bits/stdc++.h>

long long to_min_num(std::string s)
{
    size_t i = s.find('6');
    while (i != std::string::npos)
    {
        s[i] = '5';
        i = s.find('6');
    }
    return std::stoll(s);
}

long long to_max_num(std::string s)
{
    size_t i = s.find('5');
    while (i != std::string::npos)
    {
        s[i] = '6';
        i = s.find('5');
    }

    return std::stoll(s);
}

long long min_sum(std::string x_string, std::string y_string)
{
    long long x_num = to_min_num(x_string),
              y_num = to_min_num(y_string);
    return x_num + y_num;
}

long long max_sum(std::string x_string, std::string y_string)
{
    long long x_num = to_max_num(x_string),
              y_num = to_max_num(y_string);
    return x_num + y_num;
}

void string()
{
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string x, y;
        std::cin >> x >> y;
        std::cout << min_sum(x, y) << ' ' << max_sum(x, y) << '\n';
    }

    return 0;
}