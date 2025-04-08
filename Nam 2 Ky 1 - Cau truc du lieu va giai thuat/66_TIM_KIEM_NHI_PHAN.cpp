#include <iostream>
#include <vector>

void input(std::vector<int> &array, int &target)
{
    size_t size;
    std::cin >> size >> target;
    array.resize(size);
    for (int &num : array)
        std::cin >> num;
}

int find(const std::vector<int> &array, const int target)
{
    int left = 0;
    int right = array.size() - 1;
    while (left <= right)
    {
        const int middle = (left + right) / 2;
        if (array[middle] == target)
            return middle + 1;

        if (array[middle] > target)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return 0;
}

void runProgram()
{
    int target;
    std::vector<int> array;
    input(array, target);

    const int position = find(array, target);
    if (!position)
        std::cout << "NO\n";
    else
        std::cout << position << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}