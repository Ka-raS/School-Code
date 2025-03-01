#include <iostream>
#include <vector>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &num : array)
        std::cin >> num;
}

int minAbsSum(const std::vector<int> &array)
{
    int sumMin;
    int sumAbsMin = INT32_MAX;
    const size_t size = array.size();

    for (size_t i = 0; i < size - 1; ++i)
        for (size_t j = i + 1; j < size; ++j)
        {
            const int sum = array[i] + array[j];
            const int sumAbs = std::abs(sum);

            if (sumAbsMin > sumAbs)
            {
                if (sum == 0)
                    return 0;

                sumMin = sum;
                sumAbsMin = sumAbs;
            }
        }

    return sumMin;
}

void runProgram()
{
    std::vector<int> array;
    input(array);
    std::cout << minAbsSum(array) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}