#include <iostream>

size_t matrixSize;
int sumTarget;
int Matrix[21][21];
int count;

void addingSum(const size_t row, const size_t column, int sum)
{
    sum += Matrix[row][column];
    if (row == matrixSize && column == matrixSize && sum == sumTarget)
    {
        ++count;
        return;
    }
    if (row < matrixSize)
        addingSum(row + 1, column, sum);
    if (column < matrixSize)
        addingSum(row, column + 1, sum);
}

void input()
{
    std::cin >> matrixSize >> sumTarget;
    for (size_t i = 1; i <= matrixSize; ++i)
        for (size_t j = 1; j <= matrixSize; ++j)
            std::cin >> Matrix[i][j];
}

void countWays()
{
    count = 0;
    const size_t startingRow = 1,
                 startingColumn = 1;
    const int startingSum = 0;
    addingSum(startingRow, startingColumn, startingSum);
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        input();
        countWays();
        std::cout << count << std::endl;
    }
    return 0;
}