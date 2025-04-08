#include <iostream>
#include <vector>

void input(std::vector<int> &array, int &sumTarget)
{
    size_t size;
    std::cin >> size >> sumTarget;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
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

void runProgram()
{
    int sumTarget;
    std::vector<int> array;
    input(array, sumTarget);

    if (isExistSum(array, sumTarget))
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
