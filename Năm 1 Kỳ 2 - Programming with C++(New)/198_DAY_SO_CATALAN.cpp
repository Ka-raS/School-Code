// Catalan Number C(n)
// C(0) = 1 | C(1) = 1 | C(2) = 2
// C(n) = (2n)! / (n! * (n+1)!)
//
// Find Sum S(n):
// for (int k = 0; k <= n; ++k)
//     S += C(k) * C(n-k);
//
// Solution: S(n) = C(n+1)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void divideVectorA(std::vector<int> &A, int n)
{
    for (int &x : A)
    {
        const int divisor = std::__gcd(x, n);
        x /= divisor;
        n /= divisor;
        if (n == 1)
            return;
    }
}

std::string operator*(const std::string &str, const int n)
{
    if (str == "0" || n == 0)
        return "0";

    // digits are reversed
    std::string result;
    int carry = 0;

    for (auto it = str.rbegin(); it != str.rend(); ++it)
    {
        const int digitInt = *it - '0';
        const int product = digitInt * n + carry;
        const char digitChar = product % 10 + '0';
        result.push_back(digitChar);
        carry = product / 10;
    }

    // reverse back
    std::reverse(result.begin(), result.end());

    if (carry)
    {
        const std::string digitsStr = std::to_string(carry);
        result = digitsStr + result;
    }

    return result;
}

std::string Catalan(const int n)
{
    // C(n) = (2n)! / (n! * (n+1)!)
    //      = (n+2)*(n+3)...(2n) / n!

    // Step 1: Declare Vector A
    // for (int x : A)
    //     Product *= x;
    // Then: Product = (n+2)*(n+3)...(2n)
    std::vector<int> A;
    for (int value = n + 2; value <= 2 * n; ++value)
        A.push_back(value);

    // Step 2: A.elements /= n!
    // Then: Product = C
    for (int k = 2; k <= n; ++k)
        divideVectorA(A, k);

    // Step 3: Calculate C = Product of Vector A
    std::string C = "1";
    for (const int x : A)
        C = C * x;
    return C;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short n;
    std::cin >> n;

    const std::string S = Catalan(n + 1);
    std::cout << S;

    return 0;
}