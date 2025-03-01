#include <iostream>
#include <vector>

size_t minSubArraySize(const std::vector<int> &Array, const size_t size, const long long sum)
{
    size_t minSize = size + 1;
    long long sumArray = 0;
    size_t begin = 0, end = 0;
    while (end < size)
    {
        while (sumArray <= sum && end < size)
            sumArray += Array[end++];

        while (sumArray > sum && begin < size)
        {
            minSize = std::min(minSize, end - begin);
            sumArray -= Array[begin++];
        }
    }
    return minSize;
}

size_t myMinSubArraySize(const std::vector<int> &Array, const size_t size, const long long sum)
{
    long long sumArray = 0;
    size_t i;
    for (i = 0; i < size; ++i)
    {
        sumArray += Array[i];
        if (sumArray >= sum)
            break;
    }
    if (sumArray < sum)
        return size + 1;

    size_t minSize = i + 1,
           j = 0;
    for (i = i + 1; i < size; ++i)
    {
        sumArray += Array[i];
        while (sumArray - Array[j] >= sum)
        {
            sumArray -= Array[j];
            ++j;
        }
        minSize = std::min(minSize, i - j + 1);
    }
    return minSize;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        size_t size;
        long long sum;
        std::cin >> size >> sum;
        std::vector<int> Array(size);
        for (int &element : Array)
            std::cin >> element;

        const size_t minSize = myMinSubArraySize(Array, size, sum);
        if (minSize == size + 1)
            std::cout << -1 << std::endl;
        else
            std::cout << minSize << std::endl;
    }
}