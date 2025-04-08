#include <iostream>
#include <stack>
#include <unordered_set>

const std::unordered_set<char> operators = {'+', '-', '*', '/', '^'};

bool isOperator(const char c) {
    return operators.count(c);
}

std::string toInfixExpression(const std::string &str) {
    std::stack<std::string> stack;

    for (int i = str.size() - 1; i >= 0; --i) {
        if (isOperator(str[i])) {
            const std::string leftSide = stack.top();
            stack.pop();

            const std::string rightSide = stack.top();
            stack.pop();

            const std::string next = '(' + leftSide + str[i] + rightSide + ')';
            stack.emplace(next);
        } else
            stack.emplace(std::string(1, str[i]));
    }

    return stack.top();
}

void runProgram() {
    std::string prefixExpression;
    std::getline(std::cin >> std::ws, prefixExpression);
    std::cout << toInfixExpression(prefixExpression) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}