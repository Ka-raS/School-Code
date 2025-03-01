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

// array[upperBound] > target
size_t upperBound(const std::vector<int> &array, const int target)
{
    size_t begin = 0;
    size_t end = array.size();

    while (begin < end)
    {
        const size_t middle = (begin + end) / 2;
        if (array[middle] <= target)
            begin = middle + 1;
        else
            end = middle;
    }

    return begin;
}

std::vector<int> longestIncreasingSequence(const std::vector<int> &array)
{
    std::vector<int> sequence;
    sequence.reserve(array.size());

    for (const int number : array)
    {
        const size_t bound = upperBound(sequence, number);
        if (bound == sequence.size())
            sequence.emplace_back(number);
        else
            sequence[bound] = number;
    }

    return sequence;
}

void runProgram()
{
    std::vector<int> array;
    input(array);

    const size_t unmovedElements = longestIncreasingSequence(array).size();
    const size_t movedElements = array.size() - unmovedElements;
    std::cout << movedElements << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}