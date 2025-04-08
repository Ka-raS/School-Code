#include <iostream>
#include <vector>

void input(std::vector<int> &);
int ordinal(std::vector<int>);

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::vector<int> array;
        input(array);
        std::cout << ordinal(array) << std::endl;
    }
}

void input(std::vector<int> &arr)
{
    std::size_t n;
    std::cin >> n;
    arr.resize(n);

    for (int &num : arr)
        std::cin >> num;
}

void reverse(std::vector<int> &arr, std::size_t begin, std::size_t end)
{
    while (begin < end)
    {
        std::swap(arr[begin], arr[end]);
        ++begin;
        --end;
    }
}

bool prevPermutation(std::vector<int> &arr)
{
    int k = arr.size() - 2;
    while (k >= 0 && arr[k] < arr[k + 1])
        --k;
    if (k < 0)
        return false;

    std::size_t l = arr.size() - 1;
    while (arr[k] < arr[l])
        --l;

    std::swap(arr[k], arr[l]);
    reverse(arr, k + 1, arr.size() - 1);
    return true;
}

int ordinal(std::vector<int> arr)
{
    int count = 1;
    while (prevPermutation(arr))
        ++count;
    return count;
}