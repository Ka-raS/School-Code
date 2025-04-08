#include <bits/stdc++.h>

long long find_K(const std::string &N, const long long M)
{
    if (N.size() <= 18)
        return std::stoll(N) % M;

    long long remainder = 0;
    for (char digit : N)
        remainder = (remainder * 10 + digit - '0') % M;
    return remainder;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string N;
        long long M;
        std::cin >> N >> M;

        long long remainder_K = find_K(N, M);
        std::cout << remainder_K << '\n';
    }

    return 0;
}