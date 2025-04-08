#include <iostream>
#include <vector>

int findSum(const std::vector<int> &Array, const int &subArrayBegin, const int &subArrayLength)
{
    int sum = 0;
    for (int i = subArrayBegin; i < subArrayBegin + subArrayLength; ++i)
        sum += Array[i];
    return sum;
}

int findSubArrayBegin(const std::vector<int> &Array, const int &arrayLength, const int &subArrayLength)
{
    int subArrayBegin = 0;
    int sumMax = findSum(Array, subArrayBegin, subArrayLength);
    int sumTmp = sumMax;
    for (int i = subArrayLength; i < arrayLength; ++i)
    {
        sumTmp += -Array[i - subArrayLength] + Array[i];
        if (sumMax < sumTmp)
        {
            sumMax = sumTmp;
            subArrayBegin = i - subArrayLength + 1;
        }
    }
    return subArrayBegin;
}

void outputArray(const std::vector<int> &Array, const int &subArrayBegin, const int &subArrayLength)
{
    for (int i = subArrayBegin; i < subArrayBegin + subArrayLength; ++i)
        std::cout << Array[i] << ' ';
}

int main()
{
    int testCases;
    std::cin >> testCases;

    while (testCases--)
    {
        int arrayLength, subArrayLength;
        std::cin >> arrayLength >> subArrayLength;
        std::vector<int> Array(arrayLength);
        for (int &element : Array)
            std::cin >> element;

        const int subArrayBegin = findSubArrayBegin(Array, arrayLength, subArrayLength);
        outputArray(Array, subArrayBegin, subArrayLength);
        std::cout << std::endl;
    }

    return 0;
}