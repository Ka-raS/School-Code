#include <iostream>
#include <queue>
#include <vector>

void input(std::vector<std::vector<int>> &matrix) {
    size_t rows, columns;
    std::cin >> rows >> columns;
    matrix.resize(rows, std::vector<int>(columns));
    for (std::vector<int> &row : matrix) {
        for (int &number : row) {
            std::cin >> number;
        }
    }
}

struct Path {
    size_t rowPos;
    size_t colPos;
    int movesCount;

    Path(const size_t &rowPos_, const size_t &colPos_, const int &movesCount_)
        : rowPos(rowPos_), colPos(colPos_), movesCount(movesCount_) {}
};

int shortestPath(const std::vector<std::vector<int>> &matrix) {
    const size_t rows = matrix.size();
    const size_t columns = matrix[0].size();

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
    std::queue<Path> queue;
    queue.emplace(0, 0, 0);

    while (queue.empty() == false) {
        // const auto [rowPos, colPos, movesCount] = queue.front();
        const size_t rowPos = queue.front().rowPos;
        const size_t colPos = queue.front().colPos;
        const int movesCount = queue.front().movesCount;
        queue.pop();

        if (rowPos == rows - 1 && colPos == columns - 1) {
            return movesCount;
        }

        const size_t reachLength = matrix[rowPos][colPos];

        if (rowPos + reachLength < rows && visited[rowPos + reachLength][colPos] == false) {
            queue.emplace(rowPos + reachLength, colPos, movesCount + 1);
            visited[rowPos + reachLength][colPos] = true;
        }

        if (colPos + reachLength < columns && visited[rowPos][colPos + reachLength] == false) {
            queue.emplace(rowPos, colPos + reachLength, movesCount + 1);
            visited[rowPos][colPos + reachLength] = true;
        }
    }

    return -1;
}

void runProgram() {
    std::vector<std::vector<int>> matrix;
    input(matrix);
    std::cout << shortestPath(matrix) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}