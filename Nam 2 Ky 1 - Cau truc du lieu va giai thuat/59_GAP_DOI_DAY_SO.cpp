#include <iostream>
#include <array>

// {1}
// {121}
// {1213121}
// {121312141213121}
class DoubleArray
{
public:
    void startPreparations();
    int value(const int operationCounts, const long long position) const;

private:
    // std::pair{2 ^ (n - 1), n}
    std::array<long long, 50> m_exponentials;
};

void runProgram(const DoubleArray &solution)
{
    int operationCounts;
    long long position;
    std::cin >> operationCounts >> position;
    std::cout << solution.value(operationCounts, position) << std::endl;
}

int main()
{
    DoubleArray solution;
    solution.startPreparations();

    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram(solution);
}

void DoubleArray::startPreparations()
{
    m_exponentials[0] = 1;
    for (size_t i = 1; i <= m_exponentials.size(); ++i)
        m_exponentials[i] = m_exponentials[i - 1] * 2;
}

int DoubleArray::value(const int operationCounts, long long position) const
{
    for (int i = m_exponentials.size() - 1; i >= 0; --i)
    {
        if (m_exponentials[i] == position)
            return i + 1;

        if (m_exponentials[i] < position)
            position -= m_exponentials[i];
    }
}

// In other way
// void runProgram()
// {
//     int n;
//     long long k;
//     std::cin >> n >> k;
//     std::cout << __builtin_ctzll(k) + 1 << std::endl;
// }

// int main()
// {
//     int tests;
//     std::cin >> tests;
//     for (int test = 0; test < tests; ++test)
//         runProgram();
// }