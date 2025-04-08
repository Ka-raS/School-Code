#include <iostream>
#include <vector>
#include <algorithm>

void find_combinations(std::vector<std::vector<int>> &combinations,
                       const std::vector<int> &array, const int sum_target,
                       std::vector<int> combination, const std::size_t start)
{
    if (sum_target == 0)
    {
        combinations.push_back(combination);
        return;
    }

    if (sum_target < 0)
        return;

    for (std::size_t i = start; i < array.size(); ++i)
    {
        combination.push_back(array[i]);
        find_combinations(combinations, array, sum_target - array[i], combination, i + 1);
        combination.pop_back();
    }
}

void output_combinations(std::vector<int> array, const int sum_target)
{
    std::vector<std::vector<int>> combinations;
    std::sort(array.begin(), array.end());
    find_combinations(combinations, array, sum_target, {}, 0);

    if (combinations.empty())
    {
        std::cout << -1 << std::endl;
        return;
    }

    for (const std::vector<int> combination : combinations)
    {
        std::cout << '[' << combination[0];
        for (std::size_t i = 1; i < combination.size(); ++i)
            std::cout << ' ' << combination[i];
        std::cout << "] ";
    }
    std::cout << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::size_t size;
        int sum_target;
        std::cin >> size >> sum_target;
        std::vector<int> array(size);
        for (int &num : array)
            std::cin >> num;

        output_combinations(array, sum_target);
    }
}