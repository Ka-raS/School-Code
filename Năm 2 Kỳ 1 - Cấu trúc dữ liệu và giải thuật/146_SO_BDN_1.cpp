#include <iostream>
#include <list>
#include <queue>

int countConsecutiveSumNumbers(const long long &bound) {
    int count = 0;
    std::queue<long long> queue;
    queue.emplace(1);

    while (true) {
        const long long number = queue.front();
        if (number > bound) {
            break;
        }
        queue.pop();

        ++count;

        queue.emplace(number * 10);
        queue.emplace(number * 10 + 1);
    }

    return count;
}

void runProgram() {
    long long bound;
    std::cin >> bound;
    std::cout << countConsecutiveSumNumbers(bound) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}