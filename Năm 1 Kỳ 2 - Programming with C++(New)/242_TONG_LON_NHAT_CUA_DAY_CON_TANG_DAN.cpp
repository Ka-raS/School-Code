#include <iostream>
#include <vector>
#include <algorithm>

long long longestAscendingSequenceSum(const std::vector<int> &Array)
{
    std::vector<long long> Sums(Array.size(), 1);

    for (size_t i = 1; i < Array.size(); ++i)
        for (size_t j = 0; j < i; ++j)
            if (Array[j] < Array[i])
                Sums[i] = std::max(Sums[i], Sums[j] + Array[i]);
    return *std::max_element(Sums.begin(), Sums.end());
}

int main()
{
    int testCases;
    std::cin >> testCases;

    while (testCases--)
    {
        int length;
        std::cin >> length;
        std::vector<int> Array(length);
        for (int &element : Array)
            std::cin >> element;
        std::cout << longestAscendingSequenceSum(Array) << std::endl;
    }

    return 0;
}