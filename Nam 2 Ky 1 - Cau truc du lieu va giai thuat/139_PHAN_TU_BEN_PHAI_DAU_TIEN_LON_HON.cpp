#include <iostream>
#include <vector>

void input(std::vector<int> &);
void printUpperbounds(const std::vector<int> &);

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::vector<int> Array;
        input(Array);
        printUpperbounds(Array);
    }
}

void input(std::vector<int> &arr)
{
    std::size_t len;
    std::cin >> len;
    arr.resize(len);

    for (int &n : arr)
        std::cin >> n;
}

void printUpperbounds(const std::vector<int> &arr)
{
    const std::size_t n = arr.size();
    auto upper_bound = [&](const std::size_t pos) -> int
    {
        for (std::size_t i = pos + 1; i < n; ++i)
            if (arr[i] > arr[pos])
                return arr[i];
        return -1;
    };

    for (std::size_t i = 0; i < n; ++i)
        std::cout << upper_bound(i) << ' ';
    std::cout << std::endl;
}