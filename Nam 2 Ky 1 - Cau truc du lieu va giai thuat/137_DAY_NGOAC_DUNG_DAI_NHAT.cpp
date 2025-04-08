#include <iostream>
#include <stack>

size_t longestCorrect(const std::string &str) {
    size_t maxSize = 0;
    std::stack<int> stack;  // indices of '('
    stack.push(-1);         // Base index for valid sequences

    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(')
            stack.push(i);
        else {
            stack.pop();
            if (stack.empty())
                stack.push(i);
            else {
                const size_t currentSize = i - stack.top();
                maxSize = std::max(maxSize, currentSize);
            }
        }
    }

    return maxSize;
}

void runProgram() {
    std::string brackets;
    std::getline(std::cin >> std::ws, brackets);
    std::cout << longestCorrect(brackets) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}