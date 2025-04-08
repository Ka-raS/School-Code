#include <iostream>
#include <vector>

std::vector<size_t> findAscendingSequenceSizes(const std::vector<int> &Array)
{
    const size_t n = Array.size();
    std::vector<size_t> sizes(n, 1);
    for (size_t i = 1; i < n; ++i)
        for (size_t j = 0; j < i; ++j)
            if (Array[j] < Array[i])
                sizes[i] = std::max(sizes[i], sizes[j] + 1);
    return sizes;
}

std::vector<size_t> findDescendingSequenceSizes(const std::vector<int> &Array)
{
    const size_t n = Array.size();
    std::vector<size_t> sizes(n, 1);
    for (int i = n - 2; i >= 0; --i)
        for (int j = n - 1; j > i; --j)
            if (Array[j] < Array[i])
                sizes[i] = std::max(sizes[i], sizes[j] + 1);
    return sizes;
}

size_t longestBitonicSequenceSize(const std::vector<int> &Array)
{
    const std::vector<size_t> ascendingSizes = findAscendingSequenceSizes(Array),
                              descendingSizes = findDescendingSequenceSizes(Array);
    size_t sizeMax = 0;
    const size_t n = Array.size();
    for (size_t i = 0; i < n; ++i)
    {
        const size_t currentSize = ascendingSizes[i] + descendingSizes[i] - 1;
        sizeMax = std::max(sizeMax, currentSize);
    }
    return sizeMax;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        size_t size;
        std::cin >> size;
        std::vector<int> Array(size);
        for (int &element : Array)
            std::cin >> element;
        std::cout << longestBitonicSequenceSize(Array) << std::endl;
    }

    return 0;
}