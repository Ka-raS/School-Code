#include <iostream>
#include <vector>
#include <functional>

void input(std::vector<std::vector<bool>> &matrix)
{
    size_t size;
    std::cin >> size;
    matrix.resize(size, std::vector<bool>(size));
    for (std::vector<bool> &row : matrix)
    {
        for (size_t i = 0; i < size; ++i)
        {
            bool value;
            std::cin >> value;
            row[i] = value;
        }
    }
}

void printSolutions(std::vector<std::vector<bool>> &matrix)
{
    const size_t size = matrix.size();
    bool printed = false;
    std::string path;
    path.reserve(size * size);
    size_t row = 0, col = 0;

    const std::function<void()> printRecursion = [&]() -> void
    {
        if (row < 0 || col < 0 || row >= size || col >= size || matrix[row][col] == 0)
        {
            return;
        }
        if (row == size - 1 && col == size - 1)
        {
            std::cout << path << ' ';
            printed = true;
            return;
        }

        matrix[row][col] = 0;

        ++row;
        path.push_back('D');
        printRecursion();
        path.pop_back();
        --row;

        --col;
        path.push_back('L');
        printRecursion();
        path.pop_back();
        ++col;

        ++col;
        path.push_back('R');
        printRecursion();
        path.pop_back();
        --col;

        --row;
        path.push_back('U');
        printRecursion();
        path.pop_back();
        ++row;

        matrix[row][col] = 1;
    };

    printRecursion();
    if (!printed)
    {
        std::cout << -1;
    }
    std::cout << '\n';
}

void runProgram()
{
    std::vector<std::vector<bool>> matrix;
    input(matrix);
    printSolutions(matrix);
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        runProgram();
    }
}