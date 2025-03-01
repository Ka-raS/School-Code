#include <iostream>
#include <vector>

void input(std::vector<int> &array, int &pivot)
{
    size_t size;
    std::cin >> size >> pivot;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

void absoluteSort(std::vector<int> &array, const int pivot)
{
    const size_t size = array.size();

    std::vector<int> distance(size);
    for (size_t i = 0; i < size; ++i)
        distance[i] = std::abs(array[i] - pivot);

    for (size_t i = size - 1; i > 0; --i)
    {
        bool swapped = false;

        for (size_t j = 0; j < i; ++j)
            if (distance[j] > distance[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                std::swap(distance[j], distance[j + 1]);
                swapped = true;
            }

        if (swapped == false)
            break;
    }
}

void output(const std::vector<int> &array)
{
    for (const int number : array)
        std::cout << number << ' ';
    std::cout << '\n';
}

void runProgram()
{
    int pivot;
    std::vector<int> array;
    input(array, pivot);
    absoluteSort(array, pivot);
    output(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}