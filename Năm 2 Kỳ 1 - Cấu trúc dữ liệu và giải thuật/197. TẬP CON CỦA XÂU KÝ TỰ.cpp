#include <iostream>
#include <algorithm>
#include <functional>

void printSubSequences(const std::string &str)
{
    std::string sequence;
    sequence.reserve(str.size());

    const std::function<void(const size_t)> recursion = [&](const size_t pos) -> void
    {
        for (size_t i = pos; i < str.size(); ++i)
        {
            sequence.push_back(str[i]);
            std::cout << sequence << ' ';
            recursion(i + 1);
            sequence.pop_back();
        }
    };

    recursion(0);
    std::cout << '\n';
}

void runProgram()
{
    size_t size;
    std::string str;
    std::cin >> size >> str;
    printSubSequences(str);
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}