#include <bits/stdc++.h>

int convert(const std::string &num)
{
    int sum = 0;
    for (char digit : num)
        sum += digit - '0';
    return sum;
}

int find_sum_digits(int sum_digits)
{
    int sum = 0;
    while (sum_digits)
    {
        sum += sum_digits % 10;
        sum_digits /= 10;
    }
    return sum;
}

bool is_lucky(const std::string &num)
{
    int sum_digits = convert(num);
    while (sum_digits >= 10)
        sum_digits = find_sum_digits(sum_digits);
    return sum_digits == 9;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string num;
        std::cin >> num;
        std::cout << is_lucky(num) << '\n';
    }

    return 0;
}