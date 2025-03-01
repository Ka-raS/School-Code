#include <algorithm>
#include <iostream>
#include <vector>

void input(std::vector<long long> &array) {
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (long long &number : array) {
        std::cin >> number;
    }
}

bool find(const std::vector<long long> &array, size_t begin, size_t end, const long long target) {
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

bool existPythagoreanTriple(std::vector<long long> &array) {
    std::sort(array.begin(), array.end());

    for (long long &number : array) {
        number *= number;
    }
    const size_t size = array.size();
    for (size_t i = 1; i < size; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (find(array, i + 1, size, array[i] + array[j])) {
                return true;
            }
        }
    }

    return false;
}

void runProgram() {
    std::vector<long long> array;
    input(array);

    if (existPythagoreanTriple(array)) {
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