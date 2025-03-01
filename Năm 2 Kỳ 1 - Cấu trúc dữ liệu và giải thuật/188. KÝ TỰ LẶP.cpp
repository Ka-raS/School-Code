#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>

void input(std::vector<std::unordered_set<char>> &words)
{
    size_t count;
    std::cin >> count;
    words.reserve(count);
    for (size_t i = 0; i < count; i++)
    {
        std::string string;
        std::cin >> string;
        const auto begin = std::make_move_iterator(string.begin());
        const auto end = std::make_move_iterator(string.end());
        words.emplace_back(begin, end);
    }
}

int countDuplicates(const std::vector<std::unordered_set<char>> &words, const std::vector<size_t> &indices)
{
    int answer = 0;
    for (size_t i = 1; i < indices.size(); ++i)
    {
        const size_t curr = indices[i];
        const size_t prev = indices[i - 1];

        for (const char c : words[curr])
        {
            if (words[prev].find(c) != words[prev].end())
                ++answer;
        }
    }
    return answer;
}

int minDuplicates(const std::vector<std::unordered_set<char>> &words)
{
    int answer = INT32_MAX;
    const size_t count = words.size();
    std::vector<size_t> indices(count);
    std::iota(indices.begin(), indices.end(), 0);
    do
    {
        const int currentDuplicates = countDuplicates(words, indices);
        if (answer > currentDuplicates)
            answer = currentDuplicates;
    } while (std::next_permutation(indices.begin(), indices.end()));
    return answer;
}

void runProgram()
{
    std::vector<std::unordered_set<char>> words;
    input(words);
    std::cout << minDuplicates(words);
}

int main()
{
    runProgram();
}