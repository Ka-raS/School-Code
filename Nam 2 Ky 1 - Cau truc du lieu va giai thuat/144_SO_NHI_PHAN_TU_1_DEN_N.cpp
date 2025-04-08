#include <iostream>
#include <vector>
#include <algorithm>

void findBinaries(std::vector<std::string> &);

int main()
{
    std::vector<std::string> binary;
    findBinaries(binary);

    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cout << binary[i] << ' ';
        std::cout << std::endl;
    }
}

void findBinaries(std::vector<std::string> &binary)
{
    binary.push_back("0");
    for (int i = 1; i < 10000; ++i)
    {
        binary.push_back(binary[i - 1]);

        bool isConverted = false;
        for (char &c : binary[i])
        {
            if (c == '1')
                c = '0';
            else
            {
                isConverted = true;
                c = '1';
                break;
            }
        }

        if (!isConverted)
            binary[i].push_back('1');
    }

    for (std::string &str : binary)
        std::reverse(str.begin(), str.end());
}