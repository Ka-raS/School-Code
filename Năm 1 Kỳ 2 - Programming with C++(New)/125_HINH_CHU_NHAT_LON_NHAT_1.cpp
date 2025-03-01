#include <bits/stdc++.h>

std::vector<std::vector<bool>> input_matrix(const int &rows, const int &columns)
{
    bool value;
    std::vector<std::vector<bool>> Matrix(rows, std::vector<bool>(columns));

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
        {
            std::cin >> value;
            Matrix[i][j] = value;
        }

    return Matrix;
}

std::vector<std::vector<int>> fill_hist(const std::vector<std::vector<bool>> &Matrix, const int &rows, const int &columns)
{
    std::vector<std::vector<int>> hist(rows, std::vector<int>(columns));

    for (size_t j = 0; j < columns; j++)
    {
        // First row in hist[][] is copy of first row in mat[][]
        hist[0][j] = Matrix[0][j];

        // Fill remaining rows of hist[][]
        for (size_t i = 1; i < rows; i++)
        {
            if (Matrix[i][j])
                hist[i][j] = hist[i - 1][j] + 1;
            else
                hist[i][j] = 0;
        }
    }

    return hist;
}

void sort_decreasing_rows(std::vector<std::vector<int>> &hist)
{
    for (std::vector<int> &row : hist)
        std::sort(row.begin(), row.end(), std::greater<int>());
}

// Returns area of the largest rectangle of 1's
int find_max_area(const std::vector<std::vector<int>> &hist, const int &rows, const int &columns)
{
    int max_area = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            // Since values are in decreasing order,
            // The area ending with cell (i, j) can
            // be obtained by multiplying column number
            // with value of hist[i][j]
            int curr_area = (j + 1) * hist[i][j];
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }

    return max_area;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        int rows, columns;
        std::cin >> rows >> columns;
        std::vector<std::vector<bool>> Matrix = input_matrix(rows, columns);

        // An auxiliary array to store count of consecutive 1's in every column.
        std::vector<std::vector<int>> hist = fill_hist(Matrix, rows, columns);
        // Sort rows of hist in decreasing order
        sort_decreasing_rows(hist);

        int max_area = find_max_area(hist, rows, columns);
        std::cout << max_area << '\n';
    }

    return 0;
}
