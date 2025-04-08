#include <deque>
#include <iostream>

bool isTooMuchBrackets(const std::string &expression) {
    int countOpenBrackets = 0;
    int countPlusAndMinus = 0;

    for (const char letter : expression) {
        if (letter == '(') {
            ++countOpenBrackets;
        } else if (letter == '+' || letter == '-') {
            ++countPlusAndMinus;
        }
    }

    return countOpenBrackets != countPlusAndMinus;
}

void runProgram() {
    std::string expression;
    std::getline(std::cin >> std::ws, expression);

    if (isTooMuchBrackets(expression)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}