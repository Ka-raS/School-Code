#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::size_t n, k;
    std::cin >> n >> k;
    std::vector<std::string> names(n);
    for (std::string &name : names)
        std::cin >> name;

    std::set<std::string> set(names.begin(), names.end());
    names.assign(set.begin(), set.end());
    n = names.size();

    std::vector<std::size_t> indexs(k);
    for (std::size_t i = 0; i < k; ++i)
        indexs[i] = i;

    while (true)
    {
        for (const std::size_t i : indexs)
            std::cout << names[i] << ' ';
        std::cout << std::endl;

        if (indexs[0] == n - k)
            break;

        int i = k - 1;
        int tmp = n - 1;
        while (i >= 0 && indexs[i] == tmp)
        {
            --i;
            --tmp;
        }

        ++indexs[i];
        while (++i < k)
            indexs[i] = indexs[i - 1] + 1;
    }
}