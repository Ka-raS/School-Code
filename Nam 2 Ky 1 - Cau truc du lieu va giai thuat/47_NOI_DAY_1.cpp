#include <iostream>
#include <vector>
#include <queue>

void input(std::vector<int> &ropes)
{
    std::size_t size;
    std::cin >> size;
    ropes.resize(size);
    for (int &rope : ropes)
        std::cin >> rope;
}

long long minUnifiedRopeLength(const std::vector<int> &ropes)
{
    long long totalCost = 0;

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap(ropes.begin(), ropes.end());

    while (minHeap.size() > 1)
    {
        const long long a = minHeap.top();
        minHeap.pop();
        const long long b = minHeap.top();
        minHeap.pop();

        totalCost += a + b;
        minHeap.push(a + b);
    }

    return totalCost;
}

void runProgram()
{
    std::vector<int> ropes;
    input(ropes);
    std::cout << minUnifiedRopeLength(ropes) << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}