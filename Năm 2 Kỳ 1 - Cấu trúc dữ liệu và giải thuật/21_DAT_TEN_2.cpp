#include <iostream>

void output(const int, const int);

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        int n, k;
        std::cin >> n >> k;
        output(n, k);
    }
}

bool next_combination(std::string &comb, int n)
{
    const int k = comb.size();
    int i = k - 1;
    while (i >= 0 && comb[i] == ('A' + n - 1))
    {
        --i;
        --n;
    }

    if (i < 0)
        return false;
    ++comb[i];

    while (++i < k)
        comb[i] = comb[i - 1] + 1;
    return true;
}

void output(const int n, const int k)
{
    std::string comb;
    for (std::size_t i = 0; i < k; ++i)
        comb.push_back('A' + i);
    do
    {
        std::cout << comb << std::endl;
    } while (next_combination(comb, n));
}