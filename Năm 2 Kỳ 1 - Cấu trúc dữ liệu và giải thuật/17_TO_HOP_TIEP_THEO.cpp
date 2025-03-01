#include <iostream>
#include <vector>
#include <unordered_set>

// count new element of nextCombination(arr)
int count(const std::vector<int> &, const int, int);

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        int upperbound, size;
        std::cin >> upperbound >> size;
        std::vector<int> array(size);
        for (int &element : array)
            std::cin >> element;
        std::cout << count(array, size, upperbound) << std::endl;
    }
}

int count(const std::vector<int> &arr, const int n, int upper)
{
    int i = n - 1;
    while (i >= 0 && arr[i] == upper)
    {
        --i;
        --upper;
    }
    if (i < 0)
        return n;

    int count = 1;
    const int max = arr[i] + n - i;
    for (i = n - 1; i >= 0; --i)
    {
        if (arr[i] <= max)
            break;
        ++count;
    }
    return count;
}