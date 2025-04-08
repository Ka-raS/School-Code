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

void bubbleSort(std::vector<int> &array)
{
    int step = 0;
    const size_t n = array.size();

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

        output(array, step);
    }
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    bubbleSort(array);
}

int main()
{
    runProgram();
}