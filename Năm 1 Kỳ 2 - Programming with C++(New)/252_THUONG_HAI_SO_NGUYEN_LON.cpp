#include <iostream>
#include <algorithm>

void removeZeroes(std::string &);
std::string subtraction(const std::string &, const std::string &);
std::string addition(const std::string &, const std::string &);
bool str1GreaterThanstr2(const std::string &, const std::string &);

std::string division(const std::string &A, const std::string &B)
{
    if (str1GreaterThanstr2(B, A))
        return "0";

    std::string result;
    std::string S; // duplicate of string A
    for (const char c : A)
    {
        S.push_back(c);
        result.push_back('0');
        char mult = '0';
        while (str1GreaterThanstr2(S, B))
        {
            ++mult;
            S = subtraction(S, B);
            removeZeroes(S);
        }
        result = addition(result, std::string(1, mult));
    }
    if (S == B)
        result = addition(result, "1");
    removeZeroes(result);
    return result;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        std::string A, B;
        std::cin >> A >> B;
        std::cout << division(A, B) << std::endl;
    }
}

void removeZeroes(std::string &str)
{
    const size_t startPos = str.find_first_not_of('0');
    if (startPos == 0)
        return;
    if (startPos == std::string::npos)
        str = "0";
    else
        str = str.substr(startPos);
}

std::string addition(const std::string &A, const std::string &B)
{
    std::string result;
    int carry = 0;
    int i = A.length() - 1,
        j = B.length() - 1;
    while (i >= 0 || j >= 0)
    {
        const int digitA = (i >= 0) ? (A[i] - '0') : 0;
        const int digitB = (j >= 0) ? (B[j] - '0') : 0;

        int digit = digitA + digitB + carry;
        carry = digit / 10;
        digit %= 10;

        result.push_back(digit + '0');
        --i;
        --j;
    }
    if (carry != 0)
        result.push_back(carry + '0');
    std::reverse(result.begin(), result.end());
    return result;
}

std::string subtraction(const std::string &A, const std::string &B)
{
    std::string result;
    int carry = 0;
    int i = A.length() - 1,
        j = B.length() - 1;
    while (i >= 0 || j >= 0)
    {
        const int digitA = (i >= 0) ? (A[i] - '0') : 0;
        const int digitB = (j >= 0) ? (B[j] - '0') : 0;

        int digit = digitA - digitB - carry;
        if (digit < 0)
        {
            digit += 10;
            carry = 1;
        }
        else
            carry = 0;

        result.push_back(digit + '0');
        --i;
        --j;
    }
    while (result.length() > 1 && result.back() == '0')
        result.pop_back();
    std::reverse(result.begin(), result.end());
    return result;
}

bool str1GreaterThanstr2(const std::string &A, const std::string &B)
{
    if (A.length() > B.length())
        return true;
    if (A.length() < B.length())
        return false;
    return A > B; // A.length() == B.length()
}