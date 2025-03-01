#include <iostream>
#include <stack>
#include <unordered_map>

const std::unordered_map<char, char> brackets = {
    {')', '('},
    {']', '['},
    {'}', '{'},
};

bool isValid(const std::string &str)
{
    std::stack<char> openBrackets;
    for (const char c : str)
    {
        if (c == '(' || c == '[' || c == '{')
            openBrackets.push(c);
        else if (openBrackets.empty() || openBrackets.top() != brackets.at(c))
            return false;
        else
            openBrackets.pop();
    }

    return true;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::string str;
        std::cin >> str;
        if (isValid(str))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}