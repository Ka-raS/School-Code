#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int> &vector)
{
    size_t size;
    std::cin >> size;
    vector.resize(size);
    for (int &number : vector)
        std::cin >> number;
}

size_t LongestIncreasingSequenceSize(const std::vector<int> &vector)
{
    size_t maxSize = 0;

    // sizes[number] = the max size of the LIS that ends with number
    std::vector<size_t> sizes(vector.size() + 1, 0);

    for (const int &number : vector)
    {
        sizes[number] = sizes[number - 1] + 1;
        maxSize = std::max(maxSize, sizes[number]);
    }

    return maxSize;
}

int minStepsSort(const std::vector<int> &vector)
{
    // each step: move a number to the front or the back

    const size_t correctPositionedNumbers = LongestIncreasingSequenceSize(vector);
    const size_t movedNumbers = vector.size() - correctPositionedNumbers;
    return movedNumbers;
}

void runProgram()
{
    std::vector<int> vector;
    input(vector);
    std::cout << minStepsSort(vector);
}

int main()
{
    runProgram();
}