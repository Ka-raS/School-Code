#include <bitset>
#include <iostream>

std::string toBinary(const std::string &code) {
    unsigned long num = std::bitset<10>(code).to_ulong();
    unsigned long mask = num;

    while (mask) {
        mask >>= 1;
        num ^= mask;
    }

    const std::string binary = std::bitset<10>(num).to_string();
    return binary.substr(10 - code.length());
}

void runProgram() {
    std::string grayCode;
    std::cin >> grayCode;
    std::cout << toBinary(grayCode) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}