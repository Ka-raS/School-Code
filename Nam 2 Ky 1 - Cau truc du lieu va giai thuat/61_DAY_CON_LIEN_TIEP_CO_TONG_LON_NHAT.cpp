#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int> &arr)
{
    size_t size;
    std::cin >> size;
    arr.resize(size);
    for (int &num : arr)
        std::cin >> num;
}

int maxSumContinuous(const std::vector<int> &arr)
{
    int sumMax = arr[0];
    int currSum = 0;

    for (int num : arr)
    {
        // check which is better:
        //   continue the currSum (currSum = currSum + num)
        //   reset the currSum (currSum = num)
        currSum = std::max(currSum + num, num);
        sumMax = std::max(sumMax, currSum);
    }

    return sumMax;
}

void runProgram()
{
    std::vector<int> arr;
    input(arr);
    std::cout << maxSumContinuous(arr) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}