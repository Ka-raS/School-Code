#include <iostream>
#include <vector>

void output(const std::vector<int> &arr)
{
    for (const int element : arr)
        std::cout << element;
    std::cout << ' ';
}

void reverse(std::vector<int> &arr, int begin, int end)
{
    while (begin < end)
    {
        std::swap(arr[begin], arr[end]);
        ++begin;
        --end;
    }
}

bool nextReversePermutation(std::vector<int> &arr)
{
    const size_t n = arr.size();
    int k = n - 2; // max(k), arr[k] > arr[k + 1]
    while (k >= 0 && arr[k] <= arr[k + 1])
        --k;

    if (k < 0)
        return false;

    int l = n - 1; // max(l), arr[k] > arr[l]
    while (arr[k] <= arr[l])
        --l;

    std::swap(arr[k], arr[l]);
    reverse(arr, k + 1, n - 1);
    return true;
}

void printReversePermutations(const size_t n)
{
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; ++i)
        arr[i] = n - i;

    do
    {
        output(arr);
    } while (nextReversePermutation(arr));
    std::cout << std::endl;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        size_t size;
        std::cin >> size;
        printReversePermutations(size);
    }
}