#include <iostream>
#include <vector>

std::vector<int> findSpiral(const std::vector<std::vector<int>> &Matrix, const int rows, const int columns)
{
    std::vector<int> Ans;

    int firstRow = 0,
        firstColumn = 0,
        lastRow = rows - 1,
        lastColumn = columns - 1;

    while (firstRow <= lastRow || firstColumn <= lastColumn)
    {
        if (firstRow <= lastRow)
        {
            for (int i = firstColumn; i <= lastColumn; ++i)
                Ans.push_back(Matrix[firstRow][i]);
            ++firstRow;
        }
        if (firstColumn <= lastColumn)
        {
            for (int i = firstRow; i <= lastRow; ++i)
                Ans.push_back(Matrix[i][lastColumn]);
            --lastColumn;
        }
        if (firstRow <= lastRow)
        {
            for (int i = lastColumn; i >= firstColumn; --i)
                Ans.push_back(Matrix[lastRow][i]);
            --lastRow;
        }
        if (firstColumn <= lastColumn)
        {
            for (int i = lastRow; i >= firstRow; --i)
                Ans.push_back(Matrix[i][firstColumn]);
            ++firstColumn;
        }
    }

    return Ans;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    while (testCases--)
    {
        int rows, columns, position;
        std::cin >> rows >> columns >> position;
        std::vector<std::vector<int>> Matrix(rows, std::vector<int>(columns));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                std::cin >> Matrix[i][j];
        const std::vector<int> Ans = findSpiral(Matrix, rows, columns);
        std::cout << Ans[position - 1] << std::endl;
    }

    return 0;
}