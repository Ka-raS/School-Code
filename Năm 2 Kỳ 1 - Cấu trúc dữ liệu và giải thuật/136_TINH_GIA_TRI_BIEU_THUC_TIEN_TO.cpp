#include <iostream>
#include <stack>
#include <unordered_set>

const std::unordered_set<char> operators = {'+', '-', '*', '/', '^'};

bool isOperator(const char c) {
    return operators.count(c);
}

int calculate(const int left, const int right, const char Operator) {
    switch (Operator) {
    case '+':
        return left + right;

    case '-':
        return left - right;

    case '*':
        return left * right;

    case '/':
        return left / right;
    }
}

int answer(const std::string &str) {
    std::stack<int> stack;

    for (int i = str.size() - 1; i >= 0; --i) {
        if (isOperator(str[i])) {
            const int left = stack.top();
            stack.pop();

            const int right = stack.top();
            stack.pop();

            const int next = calculate(left, right, str[i]);
            stack.emplace(next);
        } else
            stack.emplace(str[i] - '0');
    }

    return stack.top();
}

void runProgram() {
    std::string prefixExpression;
    std::getline(std::cin >> std::ws, prefixExpression);
    std::cout << answer(prefixExpression) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}