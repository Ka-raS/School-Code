#include <iostream>
#include <vector>

long long maxSubarrayProduct(const std::vector<int> &Array, const int &length)
{
    long long res = Array[0];

    for (int i = 0; i < length; ++i)
    {
        long long product = 1;
        for (int j = i; j < length; ++j)
        {
            product *= Array[j];
            if (res < product)
                res = product;
        }
    }

    return res;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        int length;
        std::cin >> length;
        std::vector<int> Array(length);
        for (int &element : Array)
            std::cin >> element;
        std::cout << maxSubarrayProduct(Array, length) << std::endl;
    }

    return 0;
}