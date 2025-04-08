#include <iostream>
#include <cmath>

int countSolutions(const long long b, const int &p)
{
    int res = 0;
    for (long long x = 1; x < p; ++x)
        if (x * x % p == 1)
        {
            long long count = b / p * p;
            if (count + x > b)
                count -= p;
            res += count / p + 1;
        }

    return res;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    while (testCases--)
    {
        int b, p;
        std::cin >> b >> p;
        std::cout << countSolutions(b, p) << std::endl;
    }

    return 0;
}