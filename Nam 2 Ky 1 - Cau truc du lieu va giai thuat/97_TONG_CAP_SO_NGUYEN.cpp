#include <iostream>
#include <vector>

bool isPrime(const int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int d = 5; d * d <= n; d += 6)
        if (n % d == 0 || n % (d + 2) == 0)
            return false;

    return true;
}

void outputFirstPrimePair(const int sumTarget)
{
    for (int num = 2; num * num <= sumTarget; ++num)
        if (isPrime(num) && isPrime(sumTarget - num))
        {
            std::cout << num << ' ' << sumTarget - num << '\n';
            return;
        }
    std::cout << "-1\n";
}

void runProgram()
{
    int sumTarget;
    std::cin >> sumTarget;
    outputFirstPrimePair(sumTarget);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}