#include <iostream>
#include <vector>
#include <set>

void input(std::vector<int> &arr, int &k)
{
    std::size_t n;
    std::cin >> n >> k;
    arr.resize(n);
    for (int &num : arr)
        std::cin >> num;
}

long long maxDif(const std::vector<int> &arr, int k)
{
    std::multiset<int> set(arr.begin(), arr.end());

    long long res = 0;

    auto it = set.begin();
    k = std::min(k, (int)arr.size() - k);
    while (k--)
        res -= *it++;

    while (it != set.end())
        res += *it++;

    return res;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        int k;
        std::vector<int> arr;
        input(arr, k);
        std::cout << maxDif(arr, k) << std::endl;
    }
}