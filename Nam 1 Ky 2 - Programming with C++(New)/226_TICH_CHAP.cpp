#include <iostream>
#include <vector>

void inputMatrix(std::vector<std::vector<int>> &Matrix)
{
    for (std::vector<int> &row : Matrix)
        for (int &element : row)
            std::cin >> element;
}

long long findConvolutionElement(const std::vector<std::vector<int>> &imageMatrix, std::vector<std::vector<int>> &kernelMatrix,
                                 const size_t &rowStartingPosition, const size_t &columnStartingPosition)
{
    long long result = 0;

    for (size_t i = 0; i < kernelMatrix.size(); ++i)
        for (size_t j = 0; j < kernelMatrix.size(); ++j)
        {
            long long product = kernelMatrix[i][j];
            product *= imageMatrix[rowStartingPosition + i][columnStartingPosition + j];
            result += product;
        }

    return result;
}

std::vector<std::vector<long long>> findConvolutionMatrix(const std::vector<std::vector<int>> &imageMatrix, std::vector<std::vector<int>> &kernelMatrix)
{
    std::vector<std::vector<long long>> resultMatrix;

    const size_t imageMatrixRows    = imageMatrix.size(),
                 imageMatrixColumns = imageMatrix.front().size(),
                 rowsDistance       = imageMatrixRows    - kernelMatrix.size(),
                 columnsDistance    = imageMatrixColumns - kernelMatrix.size();

    for (size_t i = 0; i <= rowsDistance; ++i)
    {
        std::vector<long long> row;
        for (size_t j = 0; j <= columnsDistance; ++j)
        {
            const long long element = findConvolutionElement(imageMatrix, kernelMatrix, i, j);
            row.push_back(element);
        }
        resultMatrix.push_back(row);
    }

    return resultMatrix;
}

long long findSumOfElements(const std::vector<std::vector<long long>> &Matrix)
{
    long long result = 0;
    for (const std::vector<long long> &row : Matrix)
        for (const long long &element : row)
            result += element;
    return result;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        size_t imageMatrixRows, imageMatrixColumns;
        std::cin >> imageMatrixRows >> imageMatrixColumns;
        std::vector<std::vector<int>> imageMatrix(imageMatrixRows, std::vector<int>(imageMatrixColumns)),
                                      kernelMatrix(3, std::vector<int>(3));
        inputMatrix(imageMatrix);
        inputMatrix(kernelMatrix);

        const std::vector<std::vector<long long>> convolutionMatrix = findConvolutionMatrix(imageMatrix, kernelMatrix);
        const long long sumOfElements = findSumOfElements(convolutionMatrix);
        std::cout << sumOfElements << std::endl;
    }

    return 0;
}