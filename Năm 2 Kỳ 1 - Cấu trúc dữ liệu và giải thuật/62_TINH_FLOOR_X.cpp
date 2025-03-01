#include <iostream>
#include <vector>

// return index of array[floor] <= lowerBound, max(array[floor])
int floorPosition(const std::vector<long long> &array, const long long lowerBound)
{
    int left = 0;
    int right = array.size() - 1;
    int floor = -1;

    while (left <= right)
    {
        const int middle = (left + right) / 2;

        if (array[middle] == lowerBound)
            return middle + 1;

        if (array[middle] > lowerBound)
            right = middle - 1;
        else
        {
            floor = middle + 1;
            left = middle + 1;
        }
    }

    return floor;
}

void runProgram()
{
    size_t size;
    long long lowerBound;
    std::cin >> size >> lowerBound;

    std::vector<long long> array(size);
    for (long long &num : array)
        std::cin >> num;

    std::cout << floorPosition(array, lowerBound) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}