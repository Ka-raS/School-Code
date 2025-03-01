#include <iostream>
#include <vector>

void input(std::vector<std::vector<int>> &Matrix)
{
    size_t rows, columns;
    std::cin >> rows >> columns;
    Matrix.resize(rows, std::vector<int>(columns));
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            std::cin >> Matrix[i][j];
}

void transform(std::vector<std::vector<int>> &Matrix)
{
    const size_t rows = Matrix.size(),
                 columns = Matrix[0].size();
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 1; j < columns; ++j)
            if (Matrix[i][j] > 0)
                Matrix[i][j] += Matrix[i][j - 1];
}

size_t maxSubMatrix(const std::vector<std::vector<int>> &Matrix)
{
    size_t maxSize = 0;
    const size_t rows = Matrix.size(),
                 columns = Matrix[0].size();

    auto isSubMatrix = [&](const size_t rowBegin, const size_t columnBegin) -> bool
    {
        size_t currentSize = 0;
        for (size_t i = rowBegin + 1; i < rows; ++i)
        {
            if (Matrix[i][columnBegin] < Matrix[rowBegin][columnBegin])
                break;
            else
                ++currentSize;
            if (currentSize == Matrix[rowBegin][columnBegin])
                return true;
        }
        for (int i = rowBegin; i >= 0; --i)
        {
            if (Matrix[i][columnBegin] < Matrix[rowBegin][columnBegin])
                break;
            else
                ++currentSize;
            if (currentSize == Matrix[rowBegin][columnBegin])
                return true;
        }
        return false;
    };

    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            if (Matrix[i][j] > maxSize && isSubMatrix(i, j))
                maxSize = Matrix[i][j];

    return maxSize;
}

int main()
{

    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::vector<std::vector<int>> Matrix;
        input(Matrix);
        transform(Matrix);
        std::cout << maxSubMatrix(Matrix) << std::endl;
    }
}