#include <algorithm>
#include <iostream>
#include <vector>

struct Number {
    int value;
    size_t index;
};

void input(std::vector<Number> &array) {
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i].value;
        array[i].index = i;
    }
}

bool compareValue(const Number &number1, const Number &number2) {
    return number1.value < number2.value;
}

// max(A[j].index - A[i].index), A[j].value > A[i].value
int distance(std::vector<Number> array) {
    std::sort(array.begin(), array.end(), compareValue);

    int distance = INT32_MIN;
    size_t minIndex = array[0].index;
    const size_t n = array.size();

    for (size_t i = 1; i < n; ++i) {
        const int currentDistance = array[i].index - minIndex;
        if (currentDistance > distance) {
            distance = currentDistance;
        }
        if (array[i].index < minIndex) {
            minIndex = array[i].index;
        }
    }

    return distance;
}

void runProgram() {
    std::vector<Number> array;
    input(array);
    std::cout << distance(array) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}