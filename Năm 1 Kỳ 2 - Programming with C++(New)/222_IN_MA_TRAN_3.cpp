#include <iostream>
#include <vector>

void inputMatrix(std::vector<std::vector<int>> &Matrix)
{
    for (std::vector<int> &row : Matrix)
        for (int &element : row)
            std::cin >> element;
}

std::vector<int> findArray(const std::vector<std::vector<int>> &Matrix, const size_t &rows, const size_t &columns)
{
    std::vector<int> Array;

    size_t leftRow = 0,
           rightRow = 0,
           leftColumn = 0,
           rightColumn = 0;
    const size_t diagonalLines = rows + columns - 1;

    for (size_t line = 0; line < diagonalLines; ++line)
    {
        if (line % 2 == 0)
        {
            size_t i = leftRow,
                   j = leftColumn;

            while (i >= rightRow && j <= rightColumn)
            {
                Array.push_back(Matrix[i][j]);
                --i;
                ++j;
            }
        }
        else
        {
            size_t i = rightRow,
                   j = rightColumn;

            while (i <= leftRow && j >= leftColumn)
            {
                Array.push_back(Matrix[i][j]);
                ++i;
                --j;
            }
        }

        if (leftRow < rows - 1)
            ++leftRow;
        else
            ++leftColumn;

        if (rightColumn < columns - 1)
            ++rightColumn;
        else
            ++rightRow;
    }

    return Array;
}

void outputArray(const std::vector<int> &Array)
{
    for (const int &element : Array)
        std::cout << element << ' ';
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        size_t rows, columns;
        std::cin >> rows >> columns;
        std::vector<std::vector<int>> Matrix(rows, std::vector<int>(columns));
        inputMatrix(Matrix);

        const std::vector<int> Array = findArray(Matrix, rows, columns);
        outputArray(Array);
        std::cout << std::endl;
    }

    return 0;
}