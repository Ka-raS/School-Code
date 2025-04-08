#include <iostream>

int countSubStringDividableByEight(const std::string &str)
{
    int result = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        int sumDigits = 0;
        for (int j = i; j < str.size(); j++)
        {
            sumDigits += str[j] - '0';
            if (sumDigits % 3 != 0)
            {
                std::string subStr;
                if (j - 2 >= i)
                    subStr.push_back(str[j - 2]);
                if (j - 1 >= i)
                    subStr.push_back(str[j - 1]);
                subStr.push_back(str[j]);

                if (std::stoi(subStr) % 8 == 0)
                    ++result;
            }
        }
    }

    return result;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        std::string number;
        std::cin >> number;
        const int counts = countSubStringDividableByEight(number);
        std::cout << counts << std::endl;
    }

    return 0;
}