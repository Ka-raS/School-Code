#include <iostream>
#include <vector>

void input(std::vector<int> &vec)
{
    size_t size;
    std::cin >> size;
    vec.resize(size);
    for (int &num : vec)
        std::cin >> num;
}

void reverse(std::vector<int> &vec, size_t left, size_t right)
{
    while (left < right)
    {
        std::swap(vec[left], vec[right]);
        ++left;
        --right;
    }
}

bool isGreedySortable(std::vector<int> vec)
{
    if (vec.size() <= 1)
        return true;

    // assign left and right in the middle

    size_t left = (vec.size() / 2) - 1;
    size_t right = (vec.size() / 2) + (vec.size() % 2 != 0);

    while (left > 0)
    {
        if (vec[left] > vec[right])
            std::swap(vec[left], vec[right]);

        if (vec[left] > vec[left + 1] || vec[right] < vec[right - 1])
            return false;

        --left;
        ++right;
    }

    return true;
}

void runProgram()
{
    std::vector<int> vec;
    input(vec);

    if (isGreedySortable(vec))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}