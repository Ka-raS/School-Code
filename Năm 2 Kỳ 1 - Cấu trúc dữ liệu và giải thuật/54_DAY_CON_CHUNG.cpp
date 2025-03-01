#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<std::vector<int>> &vectors)
{
    for (std::vector<int> &vector : vectors)
    {
        size_t size;
        std::cin >> size;
        vector.resize(size);
    }

    for (std::vector<int> &vector : vectors)
        for (int &num : vector)
            std::cin >> num;
}

std::vector<int> findSharedElements(const std::vector<std::vector<int>> &vectors)
{
    std::vector<int> sharedElements;
    std::vector<size_t> indexs(vectors.size() - 1, 0);

    for (const int &num : vectors.back())
    {
        int numCount = 1;

        for (size_t i = 0; i < indexs.size(); ++i)
        {
            size_t &index = indexs[i];
            const std::vector<int> &vector = vectors[i];

            while (index < vector.size() && vector[index] < num)
                ++index;

            if (index >= vector.size())
                return sharedElements;

            if (vector[index] == num)
                ++numCount;
        }

        if (numCount == vectors.size())
        {
            sharedElements.push_back(num);

            for (size_t &index : indexs)
                ++index;
        }
    }

    return sharedElements;
}

void output(const std::vector<int> &vector)
{
    if (vector.empty())
        std::cout << "NO\n";

    for (const int &num : vector)
        std::cout << num << ' ';
    std::cout << '\n';
}

void runProgram()
{
    const size_t size = 3;
    std::vector<std::vector<int>> vectors(size);
    input(vectors);

    const std::vector<int> sharedElements = findSharedElements(vectors);
    output(sharedElements);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}