#include <bits/stdc++.h>

std::vector<std::string> convert(const std::string &s)
{
    std::string buf;
    std::stringstream ss(s);
    std::vector<std::string> a;

    while (ss >> buf)
    {
        for (char &c : buf)
            c = std::tolower(c);
        buf[0] = std::toupper(buf[0]);
        a.push_back(buf);
    }

    return a;
}

void print_1_first_name(const std::vector<std::string> &a)
{
    std::cout << a.back() << ' ';
    const size_t n = a.size() - 1;
    for (size_t i = 0; i < n; i++)
        std::cout << a[i] << ' ';
}

void print_1_last_name(const std::vector<std::string> &a)
{
    const size_t n = a.size();
    for (size_t i = 1; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << a[0];
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        int k;
        std::string s;
        std::cin >> k;
        std::cin.ignore();
        std::getline(std::cin, s);

        const std::vector<std::string> a = convert(s);
        switch (k)
        {
        case 1:
            print_1_first_name(a);
            break;
        case 2:
            print_1_last_name(a);
            break;
        default:
            break;
        }

        std::cout << '\n';
    }

    return 0;
}