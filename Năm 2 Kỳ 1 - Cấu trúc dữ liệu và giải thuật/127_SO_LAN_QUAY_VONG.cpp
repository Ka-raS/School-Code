#include <deque>
#include <iostream>

void input(std::deque<long long> &deque) {
    size_t size;
    std::cin >> size;
    deque.resize(size);
    for (long long &number : deque) {
        std::cin >> number;
    }
}

int rotates(std::deque<long long> &deque) {
    int count = 0;
    while (deque.front() > deque.back()) {
        const long long number = deque.front();
        deque.pop_front();
        deque.emplace_back(number);
        ++count;
    }
    return count;
}

void runProgram() {
    std::deque<long long> deque;
    input(deque);
    std::cout << rotates(deque) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}