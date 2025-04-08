#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

int arraySum(const std::vector<int> &array)
{
    int sumTotal = 0;
    for (const int number : array)
        sumTotal += number;
    return sumTotal;
}

// check if there is a sum of a sub array that is equal to sumTarget
bool isExistSum(const std::vector<int> &array, const int sumTarget)
{
    // isPosible[value] = true if sum array = value exist
    std::vector<bool> isPosible(sumTarget + 1, false);

    // sum array = 0 always true with no element
    isPosible[0] = true;

    // dynamic programming
    for (const int number : array)
        for (int sumCurrent = sumTarget; sumCurrent >= number; --sumCurrent)
        {
            const int sumPrevious = sumCurrent - number;
            if (isPosible[sumPrevious])
                isPosible[sumCurrent] = true;
        }

    return isPosible[sumTarget];
}

bool isSplitable(const std::vector<int> &array)
{
    const int sumTotal = arraySum(array);
    if (sumTotal % 2 != 0)
        return false;

    const int sumTarget = sumTotal / 2;
    return isExistSum(array, sumTarget);
}

void runProgram()
{
    std::vector<int> array;
    input(array);

    if (isSplitable(array))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}
