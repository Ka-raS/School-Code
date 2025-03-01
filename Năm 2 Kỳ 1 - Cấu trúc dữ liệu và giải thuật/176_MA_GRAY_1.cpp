#include <bitset>
#include <iostream>

void printGrayCodes(const int length) {
    const int n = 1 << length;
    for (int i = 0; i < n; ++i) {
        const int value = i ^ (i >> 1);
        const std::bitset<10> binary(value);
        const std::string code = binary.to_string();
        std::cout << code.substr(16 - length) << ' ';
    }
    std::cout << '\n';
}

void runProgram() {
    int length;
    std::cin >> length;
    printGrayCodes(length);
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
    return EXIT_SUCCESS;
}