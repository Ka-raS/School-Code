#include <iostream>
#include <unordered_map>
#include <vector>

void input(std::vector<int> &array) {
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &number : array) {
        std::cin >> number;
    }
}

size_t firstDuplicate(const std::vector<int> &array) {
    std::unordered_map<int, int> map;
    for (const int number : array) {
        ++map[number];
    }

    const size_t size = array.size();
    for (size_t i = 0; i < size; ++i) {
        if (map[array[i]] > 1) {
            return i;
        }
    }

    return size;
}

void runProgram() {
    std::vector<int> array;
    input(array);

    const size_t pos = firstDuplicate(array);
    if (pos != array.size()) {
        std::cout << array[pos] << '\n';
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