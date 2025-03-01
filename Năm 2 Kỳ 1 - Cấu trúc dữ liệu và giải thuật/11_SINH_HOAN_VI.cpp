#include <iostream>
#include <vector>
#include <algorithm>

void output(const std::vector<int> &Permutation)
{
    for (const int num : Permutation)
        std::cout << num;
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

bool next_permutation(std::vector<int> &arr)
{
    const int n = arr.size();
    int k = n - 2;
    while (k >= 0 && arr[k] >= arr[k + 1])
        --k;

    if (k < 0)
        return false;

    int l = n - 1;
    while (arr[k] >= arr[l])
        --l;

    std::swap(arr[k], arr[l]);
    reverse(arr, k + 1, n - 1);
    return true;
}

void printPermutations(const size_t size)
{
    std::vector<int> Permutation(size);
    for (size_t i = 0; i < size; ++i)
        Permutation[i] = i + 1;

    do
    {
        output(Permutation);
    } while (next_permutation(Permutation));
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
        printPermutations(size);
    }
}