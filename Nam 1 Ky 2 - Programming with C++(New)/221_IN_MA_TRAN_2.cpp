#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<int>> fillInMatrix(const int &length)
{
    std::vector<std::vector<int>> Matrix(length, std::vector<int>(length));

    int value = 0;
    for (std::vector<int> &row : Matrix)
        for (int &element : row)
            element = ++value;

    return Matrix;
}

std::vector<int> findFirstArray(const std::vector<std::vector<int>> &Matrix, const int &length)
{
    std::vector<int> Array;

    int lastRow = length / 2,
        firstRow = length / 2 - 2,
        lastColumn = length / 2 + 1,
        firstColumn = length / 2 - 1;

    while (true)
    {
        for (int i = lastRow; i > firstRow; --i)
            Array.push_back(Matrix[i][firstColumn]);
        lastRow += 2;

        for (int i = firstColumn; i < lastColumn; ++i)
            Array.push_back(Matrix[firstRow][i]);
        firstColumn -= 2;

        for (int i = firstRow; i < lastRow; ++i)
            Array.push_back(Matrix[i][lastColumn]);
        if (lastRow == length)
            break;
        firstRow -= 2;

        for (int i = lastColumn; i > firstColumn; --i)
            Array.push_back(Matrix[lastRow][i]);
        lastColumn += 2;
    }

    return Array;
}

std::vector<int> findSecondArray(const std::vector<std::vector<int>> &Matrix, const int &length)
{
    std::vector<int> Array;

    int lastRow = length / 2 + 1,
        firstRow = length / 2 - 1,
        lastColumn = length / 2,
        firstColumn = length / 2 - 2;

    while (true)
    {
        for (int i = firstRow; i < lastRow; ++i)
            Array.push_back(Matrix[i][lastColumn]);
        firstRow -= 2;

        for (int i = lastColumn; i > firstColumn; --i)
            Array.push_back(Matrix[lastRow][i]);
        lastColumn += 2;

        for (int i = lastRow; i > firstRow; --i)
            Array.push_back(Matrix[i][firstColumn]);
        if (firstRow == -1)
            break;
        lastRow += 2;

        for (int i = firstColumn; i < lastColumn; ++i)
            Array.push_back(Matrix[firstRow][i]);
        firstColumn -= 2;
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

    while (testCases--)
    {
        int length;
        std::cin >> length;
        length *= 4;

        const std::vector<std::vector<int>> Matrix = fillInMatrix(length);
        const std::vector<int> firstArray = findFirstArray(Matrix, length),
                               secondArray = findSecondArray(Matrix, length);

        outputArray(firstArray);
        std::cout << std::endl;
        outputArray(secondArray);
        std::cout << std::endl;
    }

    return 0;
}
