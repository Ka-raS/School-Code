#include <iostream>
#include <vector>

void input(std::vector<long long> &arr1, std::vector<long long> &arr2)
{
    size_t size;
    std::cin >> size;

    arr1.resize(size);
    arr2.resize(size - 1);

    for (long long &num : arr1)
        std::cin >> num;
    for (long long &num : arr2)
        std::cin >> num;
}

int differencePosition(const std::vector<long long> &arr1, const std::vector<long long> &arr2)
{
    if (arr1.back() != arr2.back())
        return arr1.size();

    int left = 0;
    int right = arr2.size() - 1;

    while (left <= right)
    {
        const int middle = (left + right) / 2;

        if (arr1[middle] == arr2[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }

    return left + 1;
}

void runProgram()
{
    std::vector<long long> arr1, arr2;
    input(arr1, arr2);
    std::cout << differencePosition(arr1, arr2) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}