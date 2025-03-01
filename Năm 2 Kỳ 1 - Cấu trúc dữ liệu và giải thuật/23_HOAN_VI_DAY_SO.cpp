#include <iostream>
#include <vector>
#include <algorithm>

void print_permutations(std::vector<int>);
void input(std::vector<int> &);

int main()
{
    std::vector<int> vector;
    input(vector);
    print_permutations(vector);
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

bool next_permutation(std::vector<int> &comb)
{
    const std::size_t n = comb.size();
    int i = n - 2;
    while (i >= 0 && comb[i] > comb[i + 1])
        --i;
    if (i < 0)
        return false;

    int j = n - 1;
    while (comb[j] < comb[i])
        --j;
    std::swap(comb[i], comb[j]);
    reverse(comb, i + 1, n - 1);
    return true;
}

void print_permutations(std::vector<int> comb)
{
    std::sort(comb.begin(), comb.end());
    do
    {
        for (const int num : comb)
            std::cout << num << ' ';
        std::cout << std::endl;
    } while (next_permutation(comb));
}

void input(std::vector<int> &arr)
{
    std::size_t n;
    std::cin >> n;
    arr.resize(n);
    for (int &num : arr)
        std::cin >> num;
}