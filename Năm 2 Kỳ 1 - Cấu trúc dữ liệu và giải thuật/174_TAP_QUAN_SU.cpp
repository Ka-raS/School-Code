#include <iostream>

int size;
int totalSize;
int soldiers[40];

void input() {
    std::cin >> totalSize >> size;
    for (int i = 0; i < size; ++i) {
        std::cin >> soldiers[i];
    }
}

int soldiersRest() {
    int i = size - 1;
    while (i >= 0 && soldiers[i] == totalSize) {
        --i;
        --totalSize;
    }

    if (i < 0) {
        return size;
    }

    if (i + 1 < size) {
        return soldiers[i + 1] - soldiers[i] - 1;
    }

    return size - i;

    // int soldiersRest = size - i;
    // const int lowBound = soldiers[i] + 1;
    // const int upBound = soldiers[i] + soldiersRest;

    // if (i + 1 < size && soldiers[i + 1] <= upBound) {
    //     const int soldierContinue = upBound - soldiers[i + 1] + 1;
    //     soldiersRest -= soldierContinue;
    // }
}

void runProgram() {
    input();
    std::cout << soldiersRest() << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
    return EXIT_SUCCESS;
}