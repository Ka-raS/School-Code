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

int isExist(const std::vector<int> &array, const int target)
{
    size_t begin = 0;
    size_t end = array.size();

    while (begin < end)
    {
        const size_t middle = (begin + end) / 2;

        if (array[middle] == target)
            return 1;

        if (array[middle] > target)
            end = middle;
        else
            begin = middle + 1;
    }

    return -1;
}

void runProgram()
{
    int target;
    std::vector<int> array;
    input(array, target);
    std::cout << isExist(array, target) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}