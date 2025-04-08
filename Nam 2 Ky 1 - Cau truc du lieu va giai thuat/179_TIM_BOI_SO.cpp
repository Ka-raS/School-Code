#include <array>
#include <iostream>

std::array<long long, 4159> divisors;

void prepare() {
    divisors[0] = 9;
    for (size_t i = 2, j = 0; i < 4159; i += 2, ++j) {
        divisors[i - 1] = divisors[j] * 10;
        divisors[i] = divisors[i - 1] + 9;
    }
}

long long minDivisor(const int number) {
    for (const long long divisor : divisors) {
        if (divisor % number == 0) {
            return divisor;
        }
    }
}

int main() {
    prepare();

    int tests;
    std::cin >> tests;
    while (tests--) {
        int number;
        std::cin >> number;
        std::cout << minDivisor(number) << '\n';
    }

    return EXIT_SUCCESS;
}