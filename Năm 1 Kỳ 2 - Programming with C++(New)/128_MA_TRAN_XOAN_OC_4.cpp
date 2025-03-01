#include <bits/stdc++.h>

void input_matrix(std::vector<int> &matrix)
{
    for (int &value : matrix)
        std::cin >> value;
}

std::vector<std::vector<int>> convert_spiral(std::vector<int> &matrix, const int size)
{
    std::vector<std::vector<int>> spiral_matrix(size, std::vector<int>(size));
    int index = 0,
        first_row = 0,
        first_column = 0,
        last_row = size - 1,
        last_column = size - 1;

    while (first_row <= last_row && first_column <= last_column)
    {
        for (int j = first_column; j <= last_column; j++)
            spiral_matrix[first_row][j] = matrix[index++];
        first_row++;

        for (int i = first_row; i <= last_row; i++)
            spiral_matrix[i][last_column] = matrix[index++];
        last_column--;

        if (first_row <= last_row)
        {
            for (int j = last_column; j >= first_column; j--)
                spiral_matrix[last_row][j] = matrix[index++];
            last_row--;
        }

        if (first_column <= last_column)
        {
            for (int i = last_row; i >= first_row; i--)
                spiral_matrix[i][first_column] = matrix[index++];
            first_column++;
        }
    }

    return spiral_matrix;
}

void output_matrix(std::vector<std::vector<int>> &matrix, const int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
}

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> matrix(size * size);
    input_matrix(matrix);

    std::sort(matrix.begin(), matrix.end());
    std::vector<std::vector<int>> spiral_matrix = convert_spiral(matrix, size);
    output_matrix(spiral_matrix, size);

    return 0;
}