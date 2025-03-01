#include <algorithm>
#include <iostream>
#include <vector>

void input(std::vector<int> &array, int &sumBound) {
    size_t size;
    std::cin >> size >> sumBound;
    array.resize(size);
    for (int &number : array) std::cin >> number;
}

long long countSums(std::vector<int> array, const int sumBound) {
    std::sort(array.begin(), array.end());

    long long countSums = 0;

    const size_t n = array.size();

    for (size_t i = 0; i < n - 2; ++i) {
        size_t left = i + 1;
        size_t right = n - 1;

        while (left < right) {
            const long long sum = (long long)array[i] + array[left] + array[right];

            if (sum < sumBound) {
                countSums += right - left;
                ++left;
            } else {
                --right;
            }
        }
    }

    return countSums;
}

void runProgram() {
    int sumBound;
    std::vector<int> array;
    input(array, sumBound);
    std::cout << countSums(array, sumBound) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}