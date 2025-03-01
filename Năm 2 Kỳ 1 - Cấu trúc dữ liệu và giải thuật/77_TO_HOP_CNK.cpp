#include <iostream>
#include <vector>
#include <numeric>

int gcd(int a, int b)
{
    while (b != 0)
    {
        const int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int product(const std::vector<int> &arr)
{
    long long result = 1;
    const int modulus = 1e9 + 7;
    for (const int num : arr)
        result = result * num % modulus;
    return result;
}

// arr /= k!
void divide(std::vector<int> &arr, const int k)
{
    for (int d = 2; d <= k; ++d)
    {
        int divisor = d;
        for (int &num : arr)
        {
            const int commonDiv = gcd(num, divisor);
            num /= commonDiv;
            divisor /= commonDiv;

            if (divisor == 1)
                break;
        }
    }
}

int combinations(const int n, int k)
{
    // nCk = nC(n-k)
    k = std::min(k, n - k);

    std::vector<int> arr(k);
    std::iota(arr.begin(), arr.end(), n - k + 1);

    divide(arr, k);
    return product(arr);
}

void runProgram()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << combinations(n, k) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}