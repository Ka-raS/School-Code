#include <iostream>
#include <vector>
#include <unordered_map>

void input(std::vector<int> &array, int &sumTarget)
{
    size_t size;
    std::cin >> size >> sumTarget;
    array.resize(size);
    for (int &number : array)
        std::cin >> number;
}

int satisfyPairs(const std::vector<int> &array, const int sumTarget)
{
    std::unordered_map<int, int> map;
    for (const int number : array)
        ++map[number];

    int count = 0;

    for (const std::pair<int, int> &pair : map)
    {
        const int number1 = pair.first;
        const int count1 = pair.second;

        if (number1 + number1 == sumTarget)
        {
            count += count1 * (count1 - 1) / 2;
            continue;
        }

        const auto it = map.find(sumTarget - number1);
        if (it == map.end())
            continue;

        const int number2 = it->first;
        const int count2 = it->second;

        count += count1 * count2;
        map.erase(it);
    }

    return count;
}

void runProgram()
{
    int sumTarget;
    std::vector<int> array;
    input(array, sumTarget);
    std::cout << satisfyPairs(array, sumTarget) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}
