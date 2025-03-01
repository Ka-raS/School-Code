#include <iostream>
#include <vector>

void input(std::vector<std::vector<bool>> &, size_t &, size_t &);
void updateHeight(std::vector<int> &, const std::vector<bool> &, const size_t);
void updateLeft(std::vector<int> &, const std::vector<bool> &, const size_t);
void updateRight(std::vector<int> &, const std::vector<bool> &, const size_t);

int maxAreaRectangle(const std::vector<std::vector<bool>> &Matrix, const size_t rows, const size_t columns)
{
    int result = 0;
    std::vector<int> height(columns, 0);
    std::vector<int> left(columns, 0);
    std::vector<int> right(columns, columns);

    for (const std::vector<bool> &row : Matrix)
    {
        updateHeight(height, row, columns);
        updateLeft(left, row, columns);
        updateRight(right, row, columns);

        for (size_t j = 0; j < columns; ++j)
            result = std::max(result, height[j] * (right[j] - left[j]));
    }

    return result;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        size_t rows, columns;
        std::vector<std::vector<bool>> Matrix;
        input(Matrix, rows, columns);
        std::cout << maxAreaRectangle(Matrix, rows, columns) << std::endl;
    }
    return 0;
}

void input(std::vector<std::vector<bool>> &Matrix, size_t &rows, size_t &columns)
{
    std::cin >> rows >> columns;
    Matrix.resize(rows, std::vector<bool>(columns));
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
        {
            int value;
            std::cin >> value;
            Matrix[i][j] = value;
        }
}

void updateHeight(std::vector<int> &height, const std::vector<bool> &row, const size_t columns)
{
    for (size_t i = 0; i < columns; ++i)
    {
        if (row[i])
            ++height[i];
        else
            height[i] = 0;
    }
}

void updateLeft(std::vector<int> &left, const std::vector<bool> &row, const size_t columns)
{
    int currentLeft = 0;
    for (size_t i = 0; i < columns; ++i)
    {
        if (row[i])
            left[i] = std::max(left[i], currentLeft);
        else
        {
            left[i] = 0;
            currentLeft = i + 1;
        }
    }
}

void updateRight(std::vector<int> &right, const std::vector<bool> &row, const size_t columns)
{
    int currentRight = columns;
    for (int i = columns - 1; i >= 0; --i)
    {
        if (row[i])
            right[i] = std::min(right[i], currentRight);
        else
        {
            right[i] = columns;
            currentRight = i;
        }
    }
}