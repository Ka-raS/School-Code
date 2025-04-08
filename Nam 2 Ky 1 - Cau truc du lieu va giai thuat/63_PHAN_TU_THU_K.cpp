#include <iostream>
#include <vector>

void input(std::vector<int> &arr1, std::vector<int> &arr2, size_t &pos)
{
    size_t size1, size2;
    std::cin >> size1 >> size2 >> pos;

    arr1.resize(size1);
    arr2.resize(size2);

    for (int &num : arr1)
        std::cin >> num;
    for (int &num : arr2)
        std::cin >> num;
}

int mergeArray(const std::vector<int> &arr1, const std::vector<int> &arr2, size_t pos)
{
    size_t i = 0;
    for (const int num1 : arr1)
    {
        while (i < arr2.size() && arr2[i] < num1)
        {
            --pos;
            if (pos == 0)
                return arr2[i];
            ++i;
        }
        --pos;
        if (pos == 0)
            return num1;
    }
}

void runProgram()
{
    size_t pos;
    std::vector<int> arr1, arr2;
    input(arr1, arr2, pos);
    std::cout << mergeArray(arr1, arr2, pos) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}