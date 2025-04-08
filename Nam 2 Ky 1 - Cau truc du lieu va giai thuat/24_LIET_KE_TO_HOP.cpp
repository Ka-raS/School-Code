#include <iostream>
#include <numeric>
#include <vector>
#include <set>

void input(std::vector<int> &, int &, int &);
void output_combinations(std::vector<int>, const int);

int main()
{
    int n, k;
    std::vector<int> arr;
    input(arr, n, k);
    output_combinations(arr, k);
}
void input(std::vector<int> &arr, int &n, int &k)
{
    std::cin >> n >> k;
    arr.resize(n);
    for (int &num : arr)
        std::cin >> num;
}

void sort_and_remove_duplicates(std::vector<int> &);
bool next_combination(std::vector<std::size_t> &, int);

void output_combinations(std::vector<int> arr, const int k)
{
    sort_and_remove_duplicates(arr);

    std::vector<std::size_t> idx(k);
    std::iota(idx.begin(), idx.end(), 0); // idx = {0, 1, 2...k}

    do
    {
        for (const std::size_t i : idx)
            std::cout << arr[i] << ' ';
        std::cout << std::endl;
    } while (next_combination(idx, arr.size() - 1));
}

void sort_and_remove_duplicates(std::vector<int> &arr)
{
    const std::set<int> set(arr.begin(), arr.end());
    arr.assign(set.begin(), set.end());
}

bool next_combination(std::vector<std::size_t> &arr, int n)
{
    const int k = arr.size();
    int i = k - 1;
    while (i >= 0 && arr[i] == n)
    {
        --i;
        --n;
    }
    if (i < 0)
        return false;

    ++arr[i];
    while (++i < k)
        arr[i] = arr[i - 1] + 1;
    return true;
}