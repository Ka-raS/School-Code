#include <iostream>
#include <vector>

void inputMatrix(std::vector<std::vector<int>> &Matrix)
{
    for (std::vector<int> &row : Matrix)
        for (int &element : row)
            std::cin >> element;
}

void outputMatrix(const std::vector<std::vector<long long>> &Matrix)
{
    for (const std::vector<long long> &row : Matrix)
    {
        for (const long long &element : row)
            std::cout << element << ' ';
        std::cout << std::endl;
    }
}

std::vector<std::vector<long long>> findConvolutionMatrix(const std::vector<std::vector<int>> &imageMatrix,
                                                          const size_t &imageMatrixRows,
                                                          const size_t &imageMatrixColumns,
                                                          const size_t &kernelMatrixSize)
{
    std::vector<std::vector<long long>> resultMatrix(1, std::vector<long long>(1));

    for (size_t i = 0; i < kernelMatrixSize; ++i)
        for (size_t j = 0; j < kernelMatrixSize; ++j)
            resultMatrix[0][0] += imageMatrix[i][j];

    const size_t rowsDistance      = imageMatrixRows    - kernelMatrixSize,
                 columnsDistance   = imageMatrixColumns - kernelMatrixSize,
                 squaredKernelSize = kernelMatrixSize   * kernelMatrixSize;

    for (size_t i = 0; i < rowsDistance; ++i)
    {
        long long element = resultMatrix[i][0];
        for (size_t j = 0; j < kernelMatrixSize; ++j)
            element = element - imageMatrix[i][j] + imageMatrix[kernelMatrixSize + i][j];
        resultMatrix.push_back({element});
    }

    for (size_t i = 0; i <= rowsDistance; ++i)
        for (size_t j = 0; j < columnsDistance; ++j)
        {
            long long element = resultMatrix[i][j];
            for (size_t k = 0; k < kernelMatrixSize; ++k)
                element = element - imageMatrix[i + k][j] + imageMatrix[i + k][j + kernelMatrixSize];
            resultMatrix[i].push_back(element);
        }
    
    for (std::vector<long long> &row : resultMatrix)
        for (long long &element : row)
            element /= squaredKernelSize;

    return resultMatrix;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        size_t imageMatrixRows, imageMatrixColumns, kernelMatrixSize;
        std::cin >> imageMatrixRows >> imageMatrixColumns >> kernelMatrixSize;
        std::vector<std::vector<int>> imageMatrix(imageMatrixRows, std::vector<int>(imageMatrixColumns));
        inputMatrix(imageMatrix);

        const std::vector<std::vector<long long>> convolutionMatrix = findConvolutionMatrix(imageMatrix, imageMatrixRows, imageMatrixColumns, kernelMatrixSize);
        outputMatrix(convolutionMatrix);
    }

    return 0;
}