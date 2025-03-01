#include <iostream>
#include <vector>
#include <functional>

void input(std::vector<std::vector<int>> &matrix, int &sumTarget)
{
    size_t size;
    std::cin >> size >> sumTarget;
    matrix.resize(size, std::vector<int>(size));
    for (std::vector<int> &row : matrix)
        for (int &num : row)
            std::cin >> num;
}

void output(const std::vector<std::vector<size_t>> &answers)
{
    std::cout << answers.size();
    for (const std::vector<size_t> &answer : answers)
    {
        std::cout << '\n';
        for (const size_t col : answer)
            std::cout << col << ' ';
    }
}

std::vector<std::vector<size_t>> findAnswers(const std::vector<std::vector<int>> &matrix, const int sumTarget)
{
    const size_t size = matrix.size();
    std::vector<bool> visited(size, false);
    std::vector<std::vector<size_t>> answers;
    std::vector<size_t> answer;
    answer.reserve(size);

    int sum = 0;
    size_t row = 0;

    const std::function<void()> recursion = [&]() -> void
    {
        if (sum == sumTarget && answer.size() == size)
        {
            answers.emplace_back(answer);
            return;
        }
        if (sum > sumTarget || row >= size || answer.size() >= size)
            return;

        for (size_t col = 0; col < size; ++col)
        {
            if (visited[col])
                continue;

            sum += matrix[row][col];
            answer.emplace_back(col + 1);
            visited[col] = true;
            ++row;
            recursion();
            --row;
            visited[col] = false;
            answer.pop_back();
            sum -= matrix[row][col];
        }
    };

    recursion();
    return answers;
}

void runProgram()
{
    int sumTarget;
    std::vector<std::vector<int>> matrix;
    input(matrix, sumTarget);
    output(findAnswers(matrix, sumTarget));
}

int main()
{
    runProgram();
}