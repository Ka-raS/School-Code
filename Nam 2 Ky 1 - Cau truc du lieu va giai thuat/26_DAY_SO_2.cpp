#include <iostream>
#include <vector>

void input(std::vector<int> &);
void output(const std::vector<int> &);
void output_triangle(const std::vector<int> &);

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::vector<int> arr;
        input(arr);
        output_triangle(arr);
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

void output_triangle(const std::vector<int> &arr)
{
    std::vector<std::vector<int>> rows;
    rows.push_back(arr);

    while (rows.back().size() > 1)
    {
        std::vector<int> new_row = rows.back();
        for (std::size_t i = 1; i < new_row.size(); ++i)
            new_row[i - 1] += new_row[i];
        new_row.pop_back();
        rows.push_back(new_row);
    }

    for (int i = rows.size() - 1; i >= 0; --i)
        output(rows[i]);
    std::cout << std::endl;
}

void output(const std::vector<int> &arr)
{
    std::cout << '[';
    for (std::size_t i = 0; i < arr.size() - 1; ++i)
        std::cout << arr[i] << ' ';
    std::cout << arr.back() << "] ";
}