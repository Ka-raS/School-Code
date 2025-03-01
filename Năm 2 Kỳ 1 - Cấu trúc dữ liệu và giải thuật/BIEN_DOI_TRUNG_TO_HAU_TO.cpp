#include <iostream>
#include <stack>
#include <unordered_map>

std::string toPostfix(const std::string &);

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::string infix;
        std::cin >> infix;
        std::cout << toPostfix(infix) << std::endl;
    }
}

const std::unordered_map<char, int> priority = {
    {'+', 0},
    {'-', 0},
    {'*', 1},
    {'/', 1},
    {'^', 2},
};

std::string toPostfix(const std::string &str)
{
    std::string res;
    std::stack<char> stack;

    for (const char c : str)
        switch (c)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if (!stack.empty() && priority.count(stack.top()) && priority.at(c) <= priority.at(stack.top()))
            {
                res.push_back(stack.top());
                stack.pop();
            }
            stack.push(c);
            break;

        case '(':
            stack.push(c);
            break;

        case ')':
            while (stack.top() != '(')
            {
                res.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
            break;

        default:
            res.push_back(c);
            break;
        }

    while (!stack.empty())
    {
        if (stack.top() != '(')
            res.push_back(stack.top());
        stack.pop();
    }

    return res;
}