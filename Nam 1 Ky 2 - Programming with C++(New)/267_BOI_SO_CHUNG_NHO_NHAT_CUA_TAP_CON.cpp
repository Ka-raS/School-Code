#include <iostream>
#include <vector>
#include <unordered_map>
#define MODULO 10007

void input(std::vector<int> &Array)
{
    size_t size;
    std::cin >> size;
    Array.resize(size);
    for (int &num : Array)
        std::cin >> num;
}

int gcd(const int a, const int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(const int a, const int b)
{
    return a / gcd(a, b) * b;
}

int sumLCMs(std::vector<int> Array)
{
    // store all lcm sums
    std::unordered_map<int, int> Sums;
    Sums[0] = 1; // starting value

    for (const int &num : Array)
    {
        // Sums replica to work on, then copy back to the original Sums after
        std::unordered_map<int, int> SumsTmp = Sums;
        for (const std::pair<const int, int> &pair : Sums)
        {
            const int lcmVal = pair.first;
            const int count = pair.second;

            int nextLcmVal;
            if (lcmVal == 0)
                nextLcmVal = num;
            else
                nextLcmVal = lcm(lcmVal, num) % MODULO;
            SumsTmp[nextLcmVal] = (SumsTmp[nextLcmVal] + count) % MODULO;
        }
        Sums = SumsTmp;
    }

    int result = 0;
    for (const std::pair<const int, int> &pair : Sums)
    {
        const int lcmVal = pair.first;
        const int count = pair.second;
        result = (result + lcmVal * count) % MODULO;
    }
    return result;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    for (int test = 1; test <= testCases; ++test)
    {
        std::vector<int> Array;
        input(Array);
        std::cout << "Case " << test << ": " << sumLCMs(Array) << std::endl;
    }
}