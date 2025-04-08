#include <algorithm>
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

int minDistance(std::vector<int> &array) {
    std::sort(array.begin(), array.end());

    int minDistance = INT32_MAX;
    const size_t n = array.size();

    for (size_t i = 1; i < n; ++i) {
        minDistance = std::min(minDistance, array[i] - array[i - 1]);
    }

    return minDistance;
}

void runProgram() {
    std::vector<int> array;
    input(array);
    std::cout << minDistance(array) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}