#include <iostream>
#include <vector>

std::vector<int> findSpiral(const std::vector<std::vector<int>> &Matrix, const int rows, const int columns)
{
    std::vector<int> Res;
    Res.reserve(rows * columns);

    int firstRow = 0;
    int firstColumn = 0;
    int lastRow = rows - 1;
    int lastColumn = columns - 1;

    while (firstRow <= lastRow || firstColumn <= lastColumn)
    {
        if (firstRow <= lastRow)
        {
            for (int i = firstColumn; i <= lastColumn; ++i)
                Res.push_back(Matrix[firstRow][i]);
            ++firstRow;
        }

        if (firstColumn <= lastColumn)
        {
            for (int i = firstRow; i <= lastRow; ++i)
                Res.push_back(Matrix[i][lastColumn]);
            --lastColumn;
        }

        if (firstRow <= lastRow)
        {
            for (int i = lastColumn; i >= firstColumn; --i)
                Res.push_back(Matrix[lastRow][i]);
            --lastRow;
        }

        if (firstColumn <= lastColumn)
        {
            for (int i = lastRow; i >= firstRow; --i)
                Res.push_back(Matrix[i][firstColumn]);
            ++firstColumn;
        }
    }

    return Res;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    while (testCases--)
    {
        int rows, columns;
        std::cin >> rows >> columns;
        std::vector<std::vector<int>> Matrix(rows, std::vector<int>(columns));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                std::cin >> Matrix[i][j];

        const std::vector<int> Ans = findSpiral(Matrix, rows, columns);
        for (int i = Ans.size() - 1; i >= 0; --i)
            std::cout << Ans[i] << ' ';
        std::cout << std::endl;
    }

    return 0;
}