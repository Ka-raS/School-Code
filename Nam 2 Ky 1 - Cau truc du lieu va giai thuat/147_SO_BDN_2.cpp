#include <iostream>
#include <queue>

long long minConsecutiveSumNumbers(const int &divisor) {
    std::queue<long long> queue;
    queue.emplace(1);

    while (queue.front() % divisor != 0) {
        const long long tmp = queue.front() * 10;
        queue.pop();
        queue.emplace(tmp);
        queue.emplace(tmp + 1);
    }

    return queue.front();
}

void runProgram() {
    int divisor;
    std::cin >> divisor;
    std::cout << minConsecutiveSumNumbers(divisor) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}