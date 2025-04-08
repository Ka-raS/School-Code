#include <iostream>
#include <vector>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

void output(const std::vector<std::vector<int>> &steps)
{
    for (int i = steps.size() - 1; i >= 0; --i)
    {
        std::cout << "Buoc " << i + 1 << ": ";

        for (const int number : steps[i])
            std::cout << number << ' ';
        std::cout << '\n';
    }
}

void swapSort(std::vector<int> &array)
{
    std::vector<std::vector<int>> steps;
    const size_t n = array.size();
    steps.reserve(n - 1);

    for (size_t i = 0; i < n - 1; ++i)
    {
        bool swapped = false;

        for (size_t j = i + 1; j < n; ++j)
            if (array[i] > array[j])
            {
                std::swap(array[i], array[j]);
                swapped = true;
            }

        if (swapped == false)
            continue;

        steps.emplace_back(array);
    }

    output(steps);
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    swapSort(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}