#include <iostream>
#include <vector>

void input(std::vector<std::vector<int>>&);
long long maxSumRectangle(const std::vector<std::vector<int>>& Matrix) {
    long long res = INT64_MIN;
    const size_t rows = Matrix.size();
    const size_t columns = Matrix[0].size();

    for (size_t k = 0; k < rows; ++k) {
        std::vector<long long> Sums(columns);
        for (size_t i = k; i < rows; ++i) {
            long long sum = 0;
            for (size_t j = 0; j < columns; ++j) {
                Sums[j] += Matrix[i][j];
                sum = std::max(Sums[j], Sums[j] + sum);
                res = std::max(res, sum);
            }
        }
    }
    return res;
}

int main() {
    int testCases;
    std::cin >> testCases;
    for (int test = 0; test < testCases; ++test) {
        std::vector<std::vector<int>> Matrix;
        input(Matrix);
        std::cout << maxSumRectangle(Matrix) << std::endl;
    }
    return 0;
}

void input(std::vector<std::vector<int>>& Matrix) {
    size_t rows, columns;
    std::cin >> rows >> columns;
    Matrix.resize(rows, std::vector<int>(columns));
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            std::cin >> Matrix[i][j];
}