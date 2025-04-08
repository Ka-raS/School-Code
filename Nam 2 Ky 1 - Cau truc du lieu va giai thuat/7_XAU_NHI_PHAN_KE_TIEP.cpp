#include <iostream>

std::string nextBinarySequence(std::string str)
{
    std::string::reverse_iterator it;
    for (it = str.rbegin(); it != str.rend(); ++it)
    {
        if (*it == '0')
            break;
        *it = '0';
    }
    if (it != str.rend())
        *it = '1';
    return str;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    for (int test = 0; test < testCases; ++test)
    {
        std::string binarySequence;
        std::cin >> binarySequence;
        std::cout << nextBinarySequence(binarySequence) << std::endl;
    }
}