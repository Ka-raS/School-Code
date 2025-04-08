#include <bits/stdc++.h>

void input_matrix(std::vector<std::vector<int>> &matrix, const int len)
{
    for (size_t i = 0; i < len; i++)
        for (size_t j = 0; j < len; j++)
            std::cin >> matrix[i][j];
}

std::vector<std::vector<int>> calculate(const std::vector<std::vector<int>> &matrix_a, const std::vector<std::vector<int>> &matrix_b, const int len_a, const int len_b)
{
    std::vector<std::vector<int>> matrix_ans(len_a, std::vector<int>(len_a));

    for (int i = 0; i < len_a; i += len_b)
        for (int j = 0; j < len_a; j += len_b)
            for (int k = 0; k < len_b; k++)
                for (int t = 0; t < len_b; t++)
                    matrix_ans[i + k][j + t] = matrix_a[i + k][j + t] * matrix_b[k][t];

    return matrix_ans;
}

void output_matrix(const std::vector<std::vector<int>> &matrix, const int len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
}

int main()
{
    int len_a;
    std::cin >> len_a;
    std::vector<std::vector<int>> matrix_a(len_a, std::vector<int>(len_a));
    input_matrix(matrix_a, len_a);

    int len_b;
    std::cin >> len_b;
    std::vector<std::vector<int>> matrix_b(len_b, std::vector<int>(len_b));
    input_matrix(matrix_b, len_b);

    matrix_a = calculate(matrix_a, matrix_b, len_a, len_b);
    output_matrix(matrix_a, len_a);

    return 0;
}