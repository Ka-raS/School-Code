#include <iostream>
#include <vector>

// bitonic sequence: a[i] < a[i + 1] < a[i + 2] <...< a[j] > a[j + 1] > a[j + 2]
size_t longestBitonicSequenceSize(const std::vector<int> &array) {
    const size_t arraySize = array.size();

    std::vector<size_t> ascending(arraySize, 1);
    std::vector<size_t> descending(arraySize, 1);

    for (size_t i = 1; i < arraySize; ++i) {
        if (array[i - 1] < array[i]) {
            ascending[i] += ascending[i - 1];
        }
    }

    for (size_t i = arraySize - 1; i > 0; --i) {
        if (array[i - 1] > array[i]) {
            descending[i - 1] += descending[i];
        }
    }

    size_t maxSize = 0;

    for (size_t i = 0; i < arraySize; ++i) {
        const size_t currentSize = ascending[i] + descending[i] - 1;
        if (maxSize < currentSize) maxSize = currentSize;
    }

    return maxSize;
}

void input(std::vector<int> &array) {
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &number : array) std::cin >> number;
}

void runProgram() {
    std::vector<int> array;
    input(array);
    std::cout << longestBitonicSequenceSize(array) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}