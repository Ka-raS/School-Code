#include <iostream>
#include <vector>
#include <queue>

void input(std::vector<std::vector<int>> &matrix)
{
    std::size_t rows, columns;
    std::cin >> rows >> columns;
    matrix.resize(rows, std::vector<int>(columns));

    for (std::vector<int> &row : matrix)
        for (int &num : row)
            std::cin >> num;
}

int paths(const std::vector<std::vector<int>> &matrix)
{
    int count = 0;

    const std::size_t rows = matrix.size();
    const std::size_t columns = matrix[0].size();
    std::queue<std::pair<std::size_t, std::size_t>> queue;
    queue.push({0, 0});

    while (!queue.empty())
    {
        const std::size_t row_idx = queue.front().first;
        const std::size_t column_idx = queue.front().second;
        queue.pop();

        if (row_idx == rows - 1 && column_idx == columns - 1)
        {
            ++count;
            continue;
        }

        if (row_idx < rows - 1)
            queue.push({row_idx + 1, column_idx});
        if (column_idx < columns - 1)
            queue.push({row_idx, column_idx + 1});
    }

    return count;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::vector<std::vector<int>> matrix;
        input(matrix);
        std::cout << paths(matrix) << std::endl;
    }
}