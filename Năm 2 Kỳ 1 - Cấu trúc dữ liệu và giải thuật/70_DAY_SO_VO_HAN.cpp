#include <iostream>
#include <array>

using Matrix = std::array<std::array<long long, 2>, 2>;

Matrix multiply(const Matrix &A, const Matrix &B)
{
    Matrix result = {{
        {0, 0},
        {0, 0},
    }};

    const int modulus = 1e9 + 7;
    const size_t size = result.size();

    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            for (size_t k = 0; k < size; ++k)
            {
                const long long product = A[i][k] * B[k][j] % modulus;
                result[i][j] = (result[i][j] + product) % modulus;
            }

    return result;
}

Matrix power(Matrix &base, int exponent)
{
    Matrix result = {{
        {1, 0},
        {0, 1},
    }};

    while (exponent > 0)
    {
        if (exponent % 2 != 0)
            result = multiply(result, base);

        exponent /= 2;
        if (exponent == 0)
            break;

        base = multiply(base, base);
    }

    return result;
}

int fibonacci(const int exponent)
{
    if (exponent <= 1)
        return exponent;
    Matrix base = {{
        {1, 1},
        {1, 0},
    }};
    const Matrix result = power(base, exponent - 1);
    return result[0][0];
}

void runProgram()
{
    int n;
    std::cin >> n;
    std::cout << fibonacci(n) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}