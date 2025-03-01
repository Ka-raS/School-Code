#include <iostream>

void nextPermutation(std::string &sequence) {
    int i = sequence.size() - 2;
    while (i >= 0 && sequence[i] >= sequence[i + 1]) {
        --i;
    }

    if (i < 0) {
        sequence = "BIGGEST";
        return;
    }

    int j = sequence.size() - 1;
    while (sequence[j] <= sequence[i]) {
        --j;
    }

    std::swap(sequence[i], sequence[j]);

    ++i;
    j = sequence.size() - 1;
    while (i < j) {
        std::swap(sequence[i], sequence[j]);
        ++i;
        --j;
    }
}

void runProgram() {
    int test;
    std::string sequence;
    std::cin >> test >> sequence;

    nextPermutation(sequence);
    std::cout << test << ' ' << sequence << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
    return EXIT_SUCCESS;
}