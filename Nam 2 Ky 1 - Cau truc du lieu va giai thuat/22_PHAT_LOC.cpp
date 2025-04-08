#include <iostream>

//  lucky number:
//      only has '8' and '6'
//      begin with '8', end with '6'
//      no '8' stands next to another '8'
//      no more than 3 '6' next to each other
void printLuckyNumbers(const std::size_t);

int main()
{
    std::size_t length;
    std::cin >> length;
    printLuckyNumbers(length);
}

std::string first_lucky_number(const std::size_t);
bool next_lucky_number(std::string &);

void printLuckyNumbers(const std::size_t n)
{
    if (n < 6)
        return;

    std::string str = first_lucky_number(n);
    do
    {
        std::cout << str << std::endl;
    } while (next_lucky_number(str));
}

std::string first_lucky_number(const std::size_t n)
{
    std::string res(n, '6');

    std::size_t i = 0;
    while (i < n)
    {
        res[i] = '8';
        i += 4; // "666" between every '8'
    }

    if (res[n - 1] == '8') // last digit must be '6'
    {
        res[n - 1] = '6';
        res[n - 2] = '8'; // move '8' to the left
    }

    return res;
}

bool next_lucky_number(std::string &str)
{
    const std::size_t n = str.length();
    std::size_t i = str.rfind('8');
    if (i < n - 3) // if str.endswith("666")
    {
        str[n - 2] = '8'; // str now ends with "686"
        return true;
    }

    while (i >= 2 && str[i - 2] == '8') // str.rfind("668") to move '8' to the left
        i -= 2;
    if (i == 0) // can't find "668", no lucky_number > current_number
        return false;

    // after move '8' to the left
    // starting from that '8', assign "666" between every '8'
    for (std::size_t j = i - 1; j < n; ++j)
    {
        if ((j - i + 1) % 4 == 0)
            str[j] = '8';
        else
            str[j] = '6';
    }

    if (str[n - 1] == '8') // last digit must be '6'
    {
        str[n - 1] = '6';
        str[n - 2] = '8'; // move '8' to the left
    }

    return true;
}