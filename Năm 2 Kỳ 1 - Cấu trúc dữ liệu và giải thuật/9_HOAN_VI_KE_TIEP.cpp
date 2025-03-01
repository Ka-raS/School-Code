#include <iostream>
#include <vector>

void input(std::vector<int> &Array)
{
    size_t size;
    std::cin >> size;
    Array.resize(size);

    for (int &element : Array)
        std::cin >> element;
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

void next_permutation(std::vector<int> &arr)
{
    const size_t n = arr.size();

    int k = n - 2; // find max(k) with arr[k] < arr[k + 1]
    while (k >= 0 && arr[k] >= arr[k + 1])
        --k;

    if (k >= 0)
    {
        int l = n - 1; // find max(l) with arr[k] < arr[l]
        while (arr[k] >= arr[l])
            --l;

        std::swap(arr[k], arr[l]);
    }

    reverse(arr, k + 1, n - 1);
}

void output(const std::vector<int> &Array)
{
    for (const int element : Array)
        std::cout << element << ' ';
    std::cout << std::endl;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    for (int test = 0; test < testCases; ++test)
    {
        std::vector<int> Array;
        input(Array);
        next_permutation(Array);
        output(Array);
    }
}