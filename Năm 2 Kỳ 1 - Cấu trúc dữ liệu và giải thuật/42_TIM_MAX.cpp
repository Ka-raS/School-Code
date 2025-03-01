#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int> &arr)
{
    std::size_t n;
    std::cin >> n;
    arr.resize(n);
    for (int &num : arr)
        std::cin >> num;
}

int max(std::vector<int> arr)
{
    long long res = 0;

    const int modulo = 1e9 + 7;
    std::sort(arr.begin(), arr.end());

    for (std::size_t i = 1; i < arr.size(); ++i)
    {
        long long tmp = arr[i];
        tmp = (tmp * i) % modulo;
        res = (res + tmp) % modulo;
    }

    return res;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::vector<int> arr;
        input(arr);
        std::cout << max(arr) << std::endl;
    }
}