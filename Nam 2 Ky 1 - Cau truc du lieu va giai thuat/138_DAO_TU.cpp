#include <iostream>
#include <sstream>
#include <stack>

std::string reverse(const std::string &str)
{
    std::string buf;
    std::istringstream ss(str);
    std::stack<std::string> stack;

    while (ss >> buf)
        stack.push(buf);

    std::ostringstream ans;
    while (!stack.empty())
    {
        ans << stack.top() << ' ';
        stack.pop();
    }

    return ans.str();
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::string str;
        std::getline(std::cin >> std::ws, str);
        std::cout << reverse(str) << std::endl;
    }
}