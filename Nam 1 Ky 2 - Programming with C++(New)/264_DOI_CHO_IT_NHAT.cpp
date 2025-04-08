#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int> &Array)
{
    size_t size;
    std::cin >> size;
    Array.resize(size);
    for (int &num : Array)
        std::cin >> num;
}

struct Element
{
    int value;
    size_t index;
};

int minSwaps(const std::vector<int> &Array)
{
    std::vector<Element> sortedArray(Array.size());
    for (size_t i = 0; i < Array.size(); ++i)
        sortedArray[i] = {Array[i], i};

    auto compareFunction = [](const Element &A, const Element &B) -> bool
    {
        if (A.value != B.value)
            return A.value < B.value;
        return A.index < B.index;
    };
    std::sort(sortedArray.begin(), sortedArray.end(), compareFunction);

    int swaps = 0;
    std::vector<bool> visited(Array.size(), false);

    for (size_t i = 0; i < sortedArray.size(); ++i)
    {
        if (visited[i] || sortedArray[i].index == i)
            continue;

        int cycleSize = 0;
        size_t j = i;
        while (!visited[j])
        {
            visited[j] = true;
            j = sortedArray[j].index;
            ++cycleSize;
        }

        if (cycleSize != 0)
            swaps += cycleSize - 1;
    }

    return swaps;
}

void startProgram()
{
    std::vector<int> Array;
    input(Array);
    std::cout << minSwaps(Array) << std::endl;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
        startProgram();
    return 0;
}
