#include <functional>
#include <iostream>

int upperBound, numCount, sumTarget;

int countCombinations(const size_t pos, const int sum, const int prev) {
    if (pos == numCount) {
        const int finalVal = sumTarget - sum;
        return finalVal > prev && finalVal <= upperBound;
    }

    int count = 0;
    for (int val = prev + 1; val <= upperBound; ++val) {
        if (sum + val > sumTarget) {
            break;
        }
        count += countCombinations(pos + 1, sum + val, val);
        int dummy = 0;
    }
    return count;
}

void runProgram() {
    while (std::cin >> upperBound >> numCount >> sumTarget) {
        if (numCount == 0) {
            break;
        }
        std::cout << countCombinations(0, 0, 0) << '\n';
    }
}

int main() {
    runProgram();
}