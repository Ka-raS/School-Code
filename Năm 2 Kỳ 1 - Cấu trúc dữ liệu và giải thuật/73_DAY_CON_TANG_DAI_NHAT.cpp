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

// array[lowerBound] >= target
size_t lowerBound(const std::vector<int> &array, const int target)
{
    size_t begin = 0;
    size_t end = array.size();

    while (begin < end)
    {
        const size_t middle = (begin + end) / 2;
        if (array[middle] < target)
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
        const size_t bound = lowerBound(sequence, number);
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
    std::cout << longestIncreasingSequence(array).size() << '\n';
}

int main()
{
    runProgram();
}
