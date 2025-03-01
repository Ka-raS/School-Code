#include <iostream>
#include <vector>

void input(std::vector<std::vector<long long>> &matrix, int &exponent)
{
    size_t size;
    std::cin >> size >> exponent;
    matrix.resize(size, std::vector<long long>(size));
    for (std::vector<long long> &row : matrix)
        for (long long &num : row)
            std::cin >> num;
}
void setEqualOne(std::vector<std::vector<long long>> &matrix, const size_t size)
{
    matrix.resize(size, std::vector<long long>(size, 0));
    for (size_t i = 0; i < size; ++i)
        matrix[i][i] = 1;
}

std::vector<std::vector<long long>> multiply(const std::vector<std::vector<long long>> &target,
                                             const std::vector<std::vector<long long>> &source)
{
    const int modulus = 1e9 + 7;
    const size_t size = target.size();
    std::vector<std::vector<long long>> result(size, std::vector<long long>(size, 0));

    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            for (size_t k = 0; k < size; ++k)
                result[i][j] = (result[i][j] + (target[i][k] * source[k][j]) % modulus) % modulus;

    return result;
}

void power(std::vector<std::vector<long long>> &base, int exponent)
{
    std::vector<std::vector<long long>> result;
    setEqualOne(result, base.size());

    while (true)
    {
        if (exponent % 2 != 0)
            result = multiply(result, base);

        exponent /= 2;
        if (exponent == 0)
            break;

        base = multiply(base, base);
    }

    base = result;
}

long long sumLastColumn(const std::vector<std::vector<long long>> &matrix)
{
    long long sum = 0;
    const int modulus = 1e9 + 7;
    for (const std::vector<long long> &row : matrix)
        sum = (sum + row.back()) % modulus;
    return sum;
}

void runProgram()
{
    int exponent;
    std::vector<std::vector<long long>> matrix;
    input(matrix, exponent);

    power(matrix, exponent);
    std::cout << sumLastColumn(matrix) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}