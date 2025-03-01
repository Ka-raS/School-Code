#include <iostream>
#include <vector>
#include <set>

void input(std::vector<std::string> &, const int);
bool next_combination(std::vector<std::size_t> &, int);

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<std::string> names;
    input(names, n);
    n = names.size() - 1;

    std::vector<std::size_t> comb(k);
    for (std::size_t i = 0; i < k; ++i)
        comb[i] = i;

    do
    {
        for (const std::size_t i : comb)
            std::cout << names[i] << ' ';
        std::cout << std::endl;
    } while (next_combination(comb, n));
}

void input(std::vector<std::string> &arr, const int n)
{
    std::set<std::string> set;
    for (int i = 0; i < n; ++i)
    {
        std::string str;
        std::cin >> str;
        set.insert(str);
    }

    for (const std::string &str : set)
        arr.push_back(str);
}

bool next_combination(std::vector<std::size_t> &comb, int n)
{
    const int k = comb.size();
    int i = k - 1;
    while (i >= 0 && comb[i] == n)
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