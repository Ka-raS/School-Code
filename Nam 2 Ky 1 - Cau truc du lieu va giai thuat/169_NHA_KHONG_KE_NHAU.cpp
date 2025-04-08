#include <iostream>
#include <vector>

void input(std::vector<int> &array) {
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &number : array) {
        std::cin >> number;
    }
}

long long maxSequenceSum(const std::vector<int> &array) {
    const size_t end = array.size();
    std::vector<long long> maxSumFromBeginTo(end + 1);
    maxSumFromBeginTo[0] = 0;
    maxSumFromBeginTo[1] = array[0];

    for (size_t i = 2; i <= end; ++i) {
        maxSumFromBeginTo[i] = std::max(maxSumFromBeginTo[i - 1], maxSumFromBeginTo[i - 2] + array[i - 1]);
    }

    return maxSumFromBeginTo[end];
}

void runProgram() {
    std::vector<int> array;
    input(array);
    std::cout << maxSequenceSum(array) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}