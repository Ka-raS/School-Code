#include <iostream>

long long fact[21];
void findFactorials()
{
    fact[0] = 1;
    for (size_t i = 1; i < 21; ++i)
        fact[i] = fact[i - 1] * i;
}

long long combinations(const int n, const int k)
{
    return fact[n] / fact[k] / fact[n - k];
}

long long possibleStrings(const int size, const int minReds, const int minBlues, const int minGreens)
{
    long long count = 0;

    const int maxReds = size - minBlues - minGreens;
    for (int reds = minReds; reds <= maxReds; ++reds)
    {
        const int maxBlues = size - reds - minGreens;
        for (int blues = minBlues; blues <= maxBlues; ++blues)
            count += combinations(size, reds) * combinations(size - reds, blues);
    }

    return count;
}

void startProgram()
{
    int size, minReds, minBlues, minGreens;
    std::cin >> size >> minReds >> minBlues >> minGreens;
    std::cout << possibleStrings(size, minReds, minBlues, minGreens) << std::endl;
}

int main()
{
    findFactorials();
    int testCases;
    std::cin >> testCases;
    while (testCases--)
        startProgram();
    return 0;
}