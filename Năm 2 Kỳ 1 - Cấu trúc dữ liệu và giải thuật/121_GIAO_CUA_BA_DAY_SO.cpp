#include <algorithm>
#include <iostream>
#include <vector>

void input(std::vector<long long> &A, std::vector<long long> &B, std::vector<long long> &C) {
    size_t sizeA, sizeB, sizeC;
    std::cin >> sizeA >> sizeB >> sizeC;

    A.resize(sizeA);
    B.resize(sizeB);
    C.resize(sizeC);

    for (long long &number : A) {
        std::cin >> number;
    }
    for (long long &number : B) {
        std::cin >> number;
    }
    for (long long &number : C) {
        std::cin >> number;
    }
}

void printIntersection(const std::vector<long long> &A, const std::vector<long long> &B,
                       const std::vector<long long> &C) {
    if (A.back() > B.back()) {
        return printIntersection(B, A, C);
    }
    if (A.back() > C.back()) {
        return printIntersection(C, B, A);
    }

    const size_t sizeB = B.size();
    const size_t sizeC = C.size();

    bool printed = false;

    size_t i = 0;
    size_t j = 0;

    for (const long long numberA : A) {
        while (i < sizeB && B[i] < numberA) {
            ++i;
        }

        while (j < sizeC && C[j] < numberA) {
            ++j;
        }

        if (numberA == B[i] && B[i] == C[j]) {
            std::cout << numberA << ' ';
            printed = true;
            ++i, ++j;
        }
    }

    if (printed == false) {
        std::cout << -1;
    }
    std::cout << '\n';
}

void runProgram() {
    std::vector<long long> A, B, C;
    input(A, B, C);
    printIntersection(A, B, C);
}

int main() {
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        runProgram();
    }
}