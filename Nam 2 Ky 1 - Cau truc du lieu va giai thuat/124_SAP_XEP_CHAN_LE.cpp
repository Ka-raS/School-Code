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

void printAlternating(const std::vector<int> &array) {
    const size_t n = array.size();
    std::vector<int> odds, evens;
    odds.reserve(n >> 1), evens.reserve(n >> 1);

    for (size_t i = 0; i < n; ++i) {
        if (i & 1) {
            evens.emplace_back(array[i]);
        } else {
            odds.emplace_back(array[i]);
        }
    }

    std::sort(odds.begin(), odds.end());
    std::sort(evens.begin(), evens.end(), std::greater<int>());

    size_t i = 0, j = 0;
    const size_t iEnd = odds.size();
    const size_t jEnd = evens.size();

    while (i < iEnd && j < jEnd) {
        std::cout << odds[i] << ' ' << evens[j] << ' ';
        ++i, ++j;
    }

    if (i < iEnd) {
        std::cout << odds[i];
    }
    if (j < jEnd) {
        std::cout << evens[j];
    }
    std::cout << '\n';
}

void runProgram() {
    std::vector<int> array;
    input(array);
    printAlternating(array);
}

int main() {
    runProgram();
}