#include <iostream>
#include <unordered_map>

void input(std::unordered_map<int, int> &map, size_t &size) {
    std::cin >> size;
    for (size_t i = 0; i < size; ++i) {
        int number;
        std::cin >> number;
        ++map[number];
    }
}

int mostAppearedNumber(const std::unordered_map<int, int> &map, const int bound) {
    int maxNumber = 0;
    int maxCount = 0;

    for (const auto &[number, count] : map) {
        if (count > bound) {
            maxNumber = number;
            maxCount = count;
        }
    }

    return maxNumber;
}

void runProgram() {
    size_t size;
    std::unordered_map<int, int> map;
    input(map, size);

    const int number = mostAppearedNumber(map, size / 2);
    if (number != 0) {
        std::cout << number << '\n';
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}