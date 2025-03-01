#include <iostream>
#include <unordered_map>
#include <vector>

void input(std::unordered_map<int, int> &map, int &sumTarget) {
    size_t size;
    std::cin >> size >> sumTarget;

    for (size_t i = 0; i < size; ++i) {
        int value;
        std::cin >> value;
        ++map[value];
    }
}

long long countSums(const std::unordered_map<int, int> &map, const int sumTarget) {
    long long countSums = 0;

    for (const std::pair<int, int> &pair : map) {
        const int number1 = pair.first;
        const long long number2 = (long long)sumTarget - number1;

        if (number1 > number2 || number2 > 1e9) {
            continue;
        }

        const int count1 = pair.second;

        if (number1 == number2) {
            countSums += (long long)count1 * (count1 - 1) / 2;
        } else if (map.count(number2)) {
            const int count2 = map.at(number2);
            countSums += (long long)count1 * count2;
        }
    }

    return countSums;
}

void runProgram() {
    int sumTarget;
    std::unordered_map<int, int> map;
    input(map, sumTarget);
    std::cout << countSums(map, sumTarget) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}