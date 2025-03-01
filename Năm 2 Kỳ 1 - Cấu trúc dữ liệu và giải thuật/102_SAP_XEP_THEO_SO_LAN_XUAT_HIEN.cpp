#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &num : array)
        std::cin >> num;
}

void output(const std::vector<int> &array)
{
    for (const int num : array)
        std::cout << num << ' ';
    std::cout << '\n';
}

void frequencySort(std::vector<int> &array)
{
    std::unordered_map<int, int> frequency;
    for (const int number : array)
        ++frequency[number];

    auto const compareFrequency = [&frequency](const int number1, const int number2) -> bool
    {
        const int frequency1 = frequency[number1];
        const int frequency2 = frequency[number2];

        if (frequency1 != frequency2)
            return frequency1 > frequency2;

        return number1 < number2;
    };

    std::sort(array.begin(), array.end(), compareFrequency);
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    frequencySort(array);
    output(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}