#include <iostream>
#include <vector>
#include <deque>

void input(std::vector<int> &array, size_t &sizeSubArray)
{
    size_t sizeArray;
    std::cin >> sizeArray >> sizeSubArray;
    array.resize(sizeArray);
    for (int &number : array)
        std::cin >> number;
}

void output(const std::vector<int> &array)
{
    for (const int number : array)
        std::cout << number << ' ';
    std::cout << '\n';
}

std::vector<int> maxOfSubArrays(const std::vector<int> &array, const size_t sizeSubArray)
{
    std::vector<int> result;
    const size_t sizeArray = array.size();
    result.reserve(sizeArray - sizeSubArray + 1);

    std::deque<size_t> queue;

    for (size_t i = 0; i < sizeArray; ++i)
    {
        // if queue.front() is out of range sizeSubArray
        if (queue.empty() == false && queue.front() == (int)i - sizeSubArray)
            queue.pop_front();

        // remove all elements <= array[i]
        while (queue.empty() == false && array[queue.back()] <= array[i])
            queue.pop_back();

        queue.emplace_back(i);

        if (i >= sizeSubArray - 1)
            result.emplace_back(array[queue.front()]);
    }

    return result;
}

void runProgram()
{
    size_t sizeSubArray;
    std::vector<int> array;
    input(array, sizeSubArray);
    output(maxOfSubArrays(array, sizeSubArray));
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}