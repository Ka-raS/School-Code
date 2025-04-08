#include <bits/stdc++.h>

unsigned long long find_a_mod(const std::string &a, const unsigned long long &mod)
{
    if (a.size() < 20)
        return std::stoull(a) % mod;

    unsigned long long a_mod = 0;
    for (char digit : a)
        a_mod = (a_mod * 10 + digit - '0') % mod;
    return a_mod;
}

unsigned long long find_k(unsigned long long a, unsigned long long b, const unsigned long long &mod)
{
    unsigned long long k = 1;

    while (b)
    {
        if (b % 2)
            k = (k * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }

    return k;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string a;
        unsigned long long b; // exponent
        unsigned long long mod;

        std::cin >> a >> b >> mod;
        unsigned long long a_mod = find_a_mod(a, mod);
        unsigned long long k = find_k(a_mod, b, mod);
        std::cout << k << '\n';
    }

    return 0;
}