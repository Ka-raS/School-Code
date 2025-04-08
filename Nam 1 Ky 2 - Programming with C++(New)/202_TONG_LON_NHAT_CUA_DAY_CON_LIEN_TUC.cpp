#include <iostream>
#include <vector>

long long sumMax(const std::vector<int> &Vector)
{
    long long res = INT32_MIN;

    long long sum = 0;
    for (const int &element : Vector)
    {
        sum += element;
        if (res < sum)
            res = sum;
        if (sum < 0)
            sum = 0;
    }

    return res;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    while (testCases--)
    {
        int length;
        std::cin >> length;
        std::vector<int> Vector(length);
        for (int &element : Vector)
            std::cin >> element;
        std::cout << sumMax(Vector) << std::endl;
    }

    return 0;
}