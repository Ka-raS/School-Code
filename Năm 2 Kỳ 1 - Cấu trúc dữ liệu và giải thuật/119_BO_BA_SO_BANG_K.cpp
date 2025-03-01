#include <algorithm>
#include <iostream>
#include <vector>

void input(std::vector<int> &array, int &sumTarget) {
    size_t size;
    std::cin >> size >> sumTarget;
    array.resize(size);
    for (int &number : array) {
        std::cin >> number;
    }
}

bool find(const std::vector<int> &array, size_t begin, size_t end, const int target) {
    while (begin < end) {
        const size_t middle = (begin + end) / 2;
        if (array[middle] == target) {
            return true;
        }

        if (array[middle] < target) {
            begin = middle + 1;
        } else {
            end = middle;
        }
    }

    return false;
}

bool isExistSum(std::vector<int> &array, const int sumTarget) {
    std::sort(array.begin(), array.end());
    const size_t size = array.size();

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            const long long number3 = (long long)sumTarget - array[i] - array[j];
            if (number3 > 1e9) {
                continue;
            }

            if (find(array, j + 1, size, number3)) {
                return true;
            }
        }
    }

    return false;
}

void runProgram() {
    int sumTarget;
    std::vector<int> array;
    input(array, sumTarget);

    if (isExistSum(array, sumTarget)) {
        std::cout << "YES\n";

    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}