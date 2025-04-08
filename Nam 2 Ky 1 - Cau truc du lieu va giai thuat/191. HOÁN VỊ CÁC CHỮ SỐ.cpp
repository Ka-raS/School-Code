#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void input(std::vector<std::string> &numbers)
{
    size_t count, dummy;
    std::cin >> count >> dummy;
    numbers.resize(count);
    for (std::string &number : numbers)
        std::cin >> number;
}

std::pair<int, int> findMinMax(const std::vector<std::string> &numbers, const std::vector<size_t> &indices)
{
    std::string min = ":";
    std::string max;

    for (const std::string &number : numbers)
    {
        std::string current;
        for (const size_t i : indices)
            current.push_back(number[i]);
        if (max.empty())
            max = current;

        if (min > current)
            min = std::move(current);
        else if (max < current)
            max = std::move(current);
    }

    return {std::stoi(min), std::stoi(max)};
}

int maxDistance(const std::vector<std::string> &numbers)
{
    int distance = INT32_MAX;
    std::vector<size_t> indices(numbers[0].size());
    std::iota(indices.begin(), indices.end(), 0);
    do
    {
        const auto [min, max] = findMinMax(numbers, indices);
        if (distance > max - min)
            distance = max - min;
    } while (std::next_permutation(indices.begin(), indices.end()));
    return distance;
}

void runProgram()
{
    std::vector<std::string> numbers;
    input(numbers);
    std::cout << maxDistance(numbers);
}

int main()
{
    runProgram();
}