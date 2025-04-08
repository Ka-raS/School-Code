#include <iostream>

int minSteps(int S, int T) {
    int count = 0;
    while (S != T) {
        if (S >= T) {
            return count + S - T;
        }
        if (T & 1) {
            ++T;
        } else {
            T >>= 1;
        }
        ++count;
    }
    return count;
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int S, T;
        std::cin >> S >> T;
        std::cout << minSteps(S, T) << std::endl;
    }
}