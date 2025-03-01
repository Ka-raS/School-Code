#include <iostream>
#include <vector>

void input(std::vector<int> &);
void output_triangular_number_pattern(std::vector<int>);

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::vector<int> arr;
        input(arr);
        output_triangular_number_pattern(arr);
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

void output(const std::vector<int> &);
bool next_row(std::vector<int> &);

void output_triangular_number_pattern(std::vector<int> arr)
{
    do
    {
        output(arr);
    } while (next_row(arr));
}

void output(const std::vector<int> &arr)
{
    std::cout << '[';
    for (std::size_t i = 0; i < arr.size() - 1; ++i)
        std::cout << arr[i] << ' ';
    std::cout << arr.back() << ']' << std::endl;
}

bool next_row(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return false;
    for (std::size_t i = 1; i < arr.size(); ++i)
        arr[i - 1] += arr[i];
    arr.pop_back();
    return true;
}