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

void sort(std::vector<int> &array)
{
    int left = 0;
    int middle = 0;
    int right = array.size() - 1;

    while (middle <= right)
        switch (array[middle])
        {
        case 0:
            std::swap(array[middle], array[left]);
            ++middle;
            ++left;
            break;

        case 1:
            ++middle;
            break;

        case 2:
            std::swap(array[middle], array[right]);
            --right;
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
    std::vector<int> array;
    input(array);
    sort(array);
    output(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}