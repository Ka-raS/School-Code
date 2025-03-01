#include <iostream>
#include <vector>
#include <algorithm>

long long maxSum(std::vector<long long> Vector, const int &length)
{
    if (length == 0)
        return 0;
    if (length == 1)
        return Vector[0];

    Vector[1] = std::max(Vector[0], Vector[1]);

    for (size_t i = 2; i < length; ++i)
        Vector[i] = std::max(Vector[i - 1], Vector[i - 2] + Vector[i]);

    return Vector[length - 1];
}

int main()
{
    int testCases;
    std::cin >> testCases;

    while (testCases--)
    {
        int length;
        std::cin >> length;
        std::vector<long long> Vector(length);
        for (long long &element : Vector)
            std::cin >> element;

        std::cout << maxSum(Vector, length) << std::endl;
    }

    return 0;
}