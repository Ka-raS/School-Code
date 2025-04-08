#include <iostream>
#include <vector>

int subtractOddElementsByOne(std::vector<int> &Array)
{
    int count = 0;
    for (int &element : Array)
        if (element % 2 == 1)
        {
            --element;
            ++count;
        }
    return count;
}

void divideAllElementsByTwo(std::vector<int> &Array)
{
    for (int &element : Array)
        element /= 2;
}

bool isAllZeros(const std::vector<int> &Array)
{
    for (const int &element : Array)
        if (element != 0)
            return false;
    return true;
}

long long operationsCount(std::vector<int> Array)
{
    long long count = 0;
    count += subtractOddElementsByOne(Array);
    if (isAllZeros(Array))
        return count;
    divideAllElementsByTwo(Array);
    ++count;
    if (isAllZeros(Array))
        return count;
    return count + operationsCount(Array);
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        int length;
        std::cin >> length;
        std::vector<int> Array(length);
        for (int &element : Array)
            std::cin >> element;
        std::cout << operationsCount(Array) << std::endl;
    }

    return 0;
}