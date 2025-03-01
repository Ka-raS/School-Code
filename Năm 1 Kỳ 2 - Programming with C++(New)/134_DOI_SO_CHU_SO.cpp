#include <bits/stdc++.h>

int find_largest(const std::string &str, const int end)
{
    int max = end;
    for (int i = str.size() - 1; i > end; i--)
        if (str[max] < str[i] && str[end - 1] > str[i])
            max = i;
    return max;
}

void swap(char &a, char &b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

void convert(std::string &str)
{
    for (int i = str.size() - 1; i > 0; i--)
        if (str[i] < str[i - 1])
        {
            int j = find_largest(str, i);
            swap(str[j], str[i - 1]);
            return;
        }
    str = "-1";
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string str;
        std::cin >> str;

        convert(str);
        std::cout << str << '\n';
    }

    return 0;
}