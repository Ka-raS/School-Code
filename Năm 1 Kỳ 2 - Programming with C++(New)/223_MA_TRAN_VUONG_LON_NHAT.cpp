#include <iostream>
#include <vector>

void inputMatrix(std::vector<std::vector<char>> &Matrix)
{
    for (std::vector<char> &row : Matrix)
        for (char &element : row)
            std::cin >> element;
}

bool isSubMatrix(const std::vector<std::vector<char>> &Matrix, const size_t &subMatrixLength, const size_t &rowStartingPosition, const size_t &columnStartingPosition)
{
    for (size_t i = 0; i < subMatrixLength; ++i)
    {
        if (Matrix[rowStartingPosition][columnStartingPosition + i] == 'O')
            return false;
        if (Matrix[rowStartingPosition + subMatrixLength - 1][columnStartingPosition + i] == 'O')
            return false;
    }
    for (size_t i = 1; i < subMatrixLength - 1; ++i)
    {
        if (Matrix[rowStartingPosition + i][columnStartingPosition] == 'O')
            return false;
        if (Matrix[rowStartingPosition + i][columnStartingPosition + subMatrixLength - 1] == 'O')
            return false;
    }
    return true;
}

bool isSubMatrixExist(const std::vector<std::vector<char>> &Matrix, const size_t &length, const size_t &subMatrixLength)
{
    const size_t distance = length - subMatrixLength;
    for (size_t i = 0; i <= distance; ++i)
        for (size_t j = 0; j <= distance; ++j)
            if (isSubMatrix(Matrix, subMatrixLength, i, j))
                return true;

    return false;
}

size_t findMaxSubMatrixLength(const std::vector<std::vector<char>> &Matrix, const size_t &length)
{
    for (size_t subMatrixLength = length; subMatrixLength > 0; --subMatrixLength)
        if (isSubMatrixExist(Matrix, length, subMatrixLength))
            return subMatrixLength;

    return 0;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        size_t length;
        std::cin >> length;
        std::vector<std::vector<char>> Matrix(length, std::vector<char>(length));
        inputMatrix(Matrix);

        const size_t maxSubMatrixLength = findMaxSubMatrixLength(Matrix, length);
        std::cout << maxSubMatrixLength << std::endl;
    }

    return 0;
}