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
        std::cout << "Buoc " << i << ": ";

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

    std::vector<int> sorted;
    sorted.reserve(n);

    for (const int number : array)
    {
        size_t i = 0;
        while (i < sorted.size() && sorted[i] <= number)
            ++i;

        if (i == sorted.size())
            sorted.emplace_back(number);
        else
        {
            sorted.emplace_back(sorted.back());

            for (size_t j = sorted.size() - 2; j > i; --j)
                sorted[j] = sorted[j - 1];

            sorted[i] = number;
        }

        steps.emplace_back(sorted);
    }

    output(steps);
    array = sorted;
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    selectionSort(array);
}

int main()
{
    runProgram();
}