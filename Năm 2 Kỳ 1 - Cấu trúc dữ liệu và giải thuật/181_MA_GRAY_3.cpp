#include <iostream>

// std::string toGrayCode(const std::string &binary) {
//     const std::bitset<10> binaryBits(binary);
//     unsigned long num = binaryBits.to_ulong();
//     num ^= num >> 1;
//     const std::bitset<10> grayCodeBits(num);
//     const std::string grayCode = grayCodeBits.to_string();
//     return grayCode.substr(10 - binary.length());
// }

unsigned long toNum(const std::string &binary) {
    int num = 0;
    for (char bit : binary) {
        num = (num << 1) | (bit - '0');
    }
    return num;
}

std::string toGrayCode(const std::string &binary) {
    int num = toNum(binary);
    num ^= num >> 1;
    std::string grayCode;
    for (size_t i = 0; i < binary.size(); ++i) {
        grayCode.push_back('0' + ((num >> (binary.size() - 1 - i)) & 1));
    }
    return grayCode;
}

void runProgram() {
    std::string binary;
    std::cin >> binary;
    std::cout << toGrayCode(binary) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}