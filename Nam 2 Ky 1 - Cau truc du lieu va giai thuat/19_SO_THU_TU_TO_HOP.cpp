#include <iostream>
#include <vector>

int ordinal(const std::vector<int> &, const int);

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        int upperbound;
        std::size_t size;
        std::cin >> upperbound >> size;
        std::vector<int> Combination(size);
        for (int &num : Combination)
            std::cin >> num;

        std::cout << ordinal(Combination, upperbound) << std::endl;
    }
}

void nextCombination(std::vector<int> &comb, int n)
{
    int i;
    const int k = comb.size();
    for (i = k - 1; i >= 0; --i)
    {
        if (comb[i] != n)
            break;
        --n;
    }

    if (i >= 0)
    {
        ++comb[i];
        ++i;
    }
    else
        i = 1;
    while (i < k)
    {
        comb[i] = comb[i - 1] + 1;
        ++i;
    }
}

int ordinal(const std::vector<int> &comb, const int n)
{
    int count = 1;
    std::vector<int> tmp(comb.size());
    for (int i = 0; i < tmp.size(); ++i)
        tmp[i] = i + 1;

    while (comb != tmp)
    {
        nextCombination(tmp, n);
        ++count;
    }
    return count;
}