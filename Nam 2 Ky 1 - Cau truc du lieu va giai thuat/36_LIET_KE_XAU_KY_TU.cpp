#include <iostream>

bool nextCombination(std::string &combination, const char c)
{
    int i = combination.size() - 1;
    while (i >= 0 && combination[i] == c)
        --i;

    if (i < 0)
        return false;

    const char newChar = combination[i] + 1;
    while (i < combination.size())
        combination[i++] = newChar;

    return true;
}

void printCombinations(const char n, const int k)
{
    std::string combination(k, 'A');
    do
    {
        std::cout << combination << std::endl;
    } while (nextCombination(combination, n));
}

int main()
{
    char n;
    int k;
    std::cin >> n >> k;
    printCombinations(n, k);
}