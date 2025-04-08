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

void selectionSort(std::vector<int> &array)
{
    const size_t n = array.size();

    std::vector<std::vector<int>> steps;
    steps.reserve(n - 1);

    for (size_t i = n - 1; i > 0; --i)
    {
        bool swapped = false;

        for (size_t j = 0; j < i; ++j)
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }

        if (swapped == false)
            break;

        steps.emplace_back(array);
    }

    output(steps);
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    selectionSort(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}