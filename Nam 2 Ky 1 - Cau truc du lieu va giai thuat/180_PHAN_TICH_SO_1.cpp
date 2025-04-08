#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int> &partition)
{
    std::cout << '(' << partition[0];
    for (size_t i = 1; i < partition.size(); ++i)
    {
        std::cout << ' ' << partition[i];
    }
    std::cout << ") ";
}

bool nextPartition(std::vector<int> &partition, const int sum)
{
    if (partition[0] == 1)
    {
        return false;
    }

    int currSum = 0;
    size_t i = 0;
    const size_t n = partition.size();
    while (i + 1 < n && partition[i + 1] != 1)
    {
        currSum += partition[i];
        ++i;
    }

    --partition[i];
    const int num = partition[i];
    currSum += num;
    partition.resize(i + 1);
    while (currSum + num < sum)
    {
        partition.emplace_back(num);
        currSum += num;
    }
    if (currSum < sum)
    {
        partition.emplace_back(sum - currSum);
    }

    return true;
}

void printPartitions(const int sum)
{
    std::vector<int> partition(1, sum);
    partition.reserve(sum);
    do
    {
        print(partition);
    } while (nextPartition(partition, sum));
    std::cout << '\n';
}

void runProgram()
{
    int sum;
    std::cin >> sum;
    printPartitions(sum);
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        runProgram();
    }
    return EXIT_SUCCESS;
}