#include <iostream>

void reverse(std::string &str, int begin, int end)
{
    while (begin < end)
    {
        std::swap(str[begin], str[end]);
        ++begin;
        --end;
    }
}

bool next_permutation(std::string &str)
{
    int i = str.size() - 2;
    while (i >= 0 && str[i] > str[i + 1])
        --i;

    if (i < 0)
        return false;

    int j = str.size() - 1;
    while (str[j] < str[i])
        --j;

    std::swap(str[i], str[j]);
    reverse(str, i + 1, str.size() - 1);
    return true;
}

void output_permutations(std::string str)
{
    do
    {
        std::cout << str << ' ';
    } while (next_permutation(str));
    std::cout << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::string str;
        std::cin >> str;
        output_permutations(str);
    }
}
