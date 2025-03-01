#include <array>
#include <iostream>

class LuckyNumbers {
public:
    void findLuckyNumbers() {
        m_numbers[0] = 6, m_numbers[1] = 8;
        for (size_t i = 2; i < INT16_MAX; i += 2) {
            m_numbers[i] = m_numbers[(i >> 1) - 1] * 10 + 6;
            m_numbers[i + 1] = m_numbers[(i >> 1) - 1] * 10 + 8;
        }

        for (size_t i = 0; i < 15; ++i) {
            m_positions[i] = (1 << (i + 1)) - 3;
        }
    }

    void printLuckyNumbers(const size_t &lengthBound) const {
        int i = m_positions[lengthBound];
        std::cout << i + 1 << '\n';

        while (i >= 0) {
            std::cout << m_numbers[i--] << ' ';
        }
        std::cout << '\n';
    }

private:
    std::array<long long, INT16_MAX> m_numbers;
    std::array<int, 15> m_positions;
};

void runProgram(const LuckyNumbers &solution) {
    size_t lengthBound;
    std::cin >> lengthBound;
    solution.printLuckyNumbers(lengthBound);
}

int main() {
    LuckyNumbers solution;
    solution.findLuckyNumbers();

    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram(solution);
    }
}