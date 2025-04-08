#include <iostream>
#include <vector>

void input(std::vector<int> &array, size_t &subSize) {
    size_t size;
    std::cin >> size >> subSize;
    array.resize(size);
    for (int &number : array) {
        std::cin >> number;
    }
}

int countAscendSubSequence(const std::vector<int> &array, const size_t subSize) {
    std::vector<std::vector<int>> dp(subSize + 1, std::vector<int>(array.size(), 0));
    for (int &count : dp[1]) {
        count = 1;
    }

    for (size_t s = 2; s <= subSize; ++s) {
        for (size_t i = 1; i < array.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (array[i] > array[j]) {
                    dp[s][i] += dp[s - 1][j];
                }
            }
        }
    }

    int totalCount = 0;
    for (const int count : dp[subSize]) {
        totalCount += count;
    }
    return totalCount;
}

void runProgram() {
    size_t subSize;
    std::vector<int> array;
    input(array, subSize);
    std::cout << countAscendSubSequence(array, subSize);
}

int main() {
    runProgram();
    return EXIT_SUCCESS;
}