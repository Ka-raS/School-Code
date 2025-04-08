#include <iostream>
#include <queue>

// min number % divisor == 0, makes up of '0' and '9'
long long number(const int divisor) {
    std::queue<std::string> queue;
    queue.emplace("9");

    while (true) {
        const std::string str = queue.front();
        const long long num = std::stoll(str);
        queue.pop();

        if (num % divisor == 0) {
            return num;
        }

        queue.emplace(str + '0');
        queue.emplace(str + '9');
    }
}

void runProgram() {
    int divisor;
    std::cin >> divisor;
    std::cout << number(divisor) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}