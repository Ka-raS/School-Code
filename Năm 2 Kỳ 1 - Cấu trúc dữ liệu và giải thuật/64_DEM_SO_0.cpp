#include <iostream>
#include <vector>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &num : array)
        std::cin >> num;
}

int countZeros(const std::vector<int> &array)
{
    int left = 0;
    int right = array.size() - 1;
    while (left <= right)
    {
        const int middle = (left + right) / 2;
        if (array[middle] == 0)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return left;
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    std::cout << countZeros(array) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}