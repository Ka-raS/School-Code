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
    std::cout << "Buoc " << ++step << ": ";
    for (const int num : array)
        std::cout << num << ' ';
    std::cout << '\n';
}

void selectionSort(std::vector<int> &array)
{
    int step = 0;
    const size_t n = array.size();

    for (size_t i = 0; i < n - 1; ++i)
    {
        size_t max = i;

        for (size_t j = i + 1; j < n; ++j)
            if (array[j] > array[max])
                max = j;

        if (max != i)
        {
            std::swap(array[i], array[max]);
            output(array, step);
        }
    }
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