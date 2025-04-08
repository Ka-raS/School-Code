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

int sum(const std::vector<int> &array) {
    int sum = 0;
    for (const int number : array) {
        sum += number;
    }
    return sum;
}

int middle(const std::vector<int> &array) {
    int leftSum = sum(array) - array[0];
    int rightSum = 0;
    if (rightSum == leftSum) {
        return 1;
    }

    const size_t n = array.size();
    for (size_t i = 1; i < n; ++i) {
        rightSum += array[i - 1];
        leftSum -= array[i];

        if (rightSum == leftSum) {
            return i + 1;
        }
    }

    return -1;
}

void runProgram() {
    std::vector<int> array;
    input(array);
    std::cout << middle(array) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}