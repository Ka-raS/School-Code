#include <iostream>
#include <vector>

void input(std::vector<int> &array, int &target)
{
    size_t size;
    std::cin >> size >> target;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

void output(const std::vector<int> &array)
{
    for (const int num : array)
        std::cout << num << ' ';
    std::cout << '\n';
}

size_t position(const std::vector<int> &array, const int target)
{
    size_t left = 0;
    size_t right = array.size();

    while (left < right)
    {
        const size_t middle = (left + right) / 2;
        if (array[middle] == target)
            return middle + 1;

        if (array[left] <= array[middle])
        {
            if (array[left] <= target && target <= array[middle])
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        else
        {
            if (array[middle] <= target && target <= array[right])
            {
                left = middle;
            }
            else
            {
                right = middle - 1;
            }
        }
    }
}

void runProgram()
{
    int target;
    std::vector<int> array;
    input(array, target);
    std::cout << position(array, target) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}