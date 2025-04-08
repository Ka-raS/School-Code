#include <iostream>
#include <vector>
#include <set>

void input(std::vector<int> &arr)
{
    std::size_t n;
    std::cin >> n;
    arr.resize(n);
    for (int &num : arr)
        std::cin >> num;
}

long long minSum(const std::vector<int> &arr)
{
    std::multiset<int> set(arr.begin(), arr.end());

    long long num1 = 0;
    long long num2 = 0;

    auto it = set.begin();
    while (it != set.end())
    {
        num1 = 10 * num1 + *it++;
        if (it != set.end())
            num2 = 10 * num2 + *it++;
    }

    return num1 + num2;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::vector<int> arr;
        input(arr);
        std::cout << minSum(arr) << std::endl;
    }
}