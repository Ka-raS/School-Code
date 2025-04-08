#include <algorithm>
#include <iostream>
#include <vector>

void input(std::vector<int> &vector, int &differenceBound) {
    size_t size;
    std::cin >> size >> differenceBound;
    vector.resize(size);
    for (int &number : vector) {
        std::cin >> number;
    }
}

long long countDifferences(std::vector<int> &vector, const int differenceBound) {
    std::sort(vector.begin(), vector.end());

    long long count = 0;
    size_t right = 1;
    const size_t size = vector.size();

    for (size_t left = 0; left < right; ++left) {
        while (right < size && vector[right] - vector[left] < differenceBound) {
            ++right;
        }

        count += right - left - 1;
    }

    return count;
}

void runProgram() {
    int differenceBound;
    std::vector<int> vector;
    input(vector, differenceBound);
    std::cout << countDifferences(vector, differenceBound) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}