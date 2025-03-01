#include <iostream>
#include <vector>

void findAllCombinations(std::vector<int> combination, const size_t start,
                         std::vector<std::vector<int>> &Combinations,
                         const std::vector<int> &Array, const int sumTarget)
{
    if (sumTarget == 0)
    {
        Combinations.push_back(combination);
        return;
    }
    if (sumTarget < 0)
        return;

    for (size_t i = start; i < Array.size(); ++i)
    {
        combination.push_back(Array[i]);
        findAllCombinations(combination, i + 1, Combinations, Array, sumTarget - Array[i]);
        combination.pop_back();
    }
}

int main()
{
    size_t size;
    int sumTarget;
    std::cin >> size >> sumTarget;
    std::vector<int> Array(size);
    for (int &element : Array)
        std::cin >> element;

    std::vector<int> combination;
    std::vector<std::vector<int>> Combinations;
    findAllCombinations(combination, 0, Combinations, Array, sumTarget);

    for (auto it = Combinations.rbegin(); it != Combinations.rend(); ++it)
    {
        for (const int element : *it)
            std::cout << element << ' ';
        std::cout << std::endl;
    }
    std::cout << Combinations.size();
}