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

void output(const std::vector<int> &array, int &step)
{
    std::cout << "Buoc " << step++ << ": ";
    for (const int num : array)
        std::cout << num << ' ';
    std::cout << '\n';
}

void selectionSort(std::vector<int> &array)
{
    int step = 0;
    std::vector<int> sorted;
    sorted.reserve(array.size());

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

        output(sorted, step);
    }

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