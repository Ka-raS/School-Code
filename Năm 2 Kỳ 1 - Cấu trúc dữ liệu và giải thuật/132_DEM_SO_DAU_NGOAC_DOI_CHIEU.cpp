#include <iostream>

int minChangeBrackets(const std::string &expression) {
    int countSwitch = 0;
    int countOpenBrackets = 0;

    for (const char bracket : expression) {
        if (bracket == '(')
            ++countOpenBrackets;
        else if (countOpenBrackets == 0) {
            ++countOpenBrackets;
            ++countSwitch;
        } else
            --countOpenBrackets;
    }

    countSwitch += countOpenBrackets / 2;

    return countSwitch;
}

void runProgram() {
    std::string expression;
    std::getline(std::cin >> std::ws, expression);
    std::cout << minChangeBrackets(expression) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}