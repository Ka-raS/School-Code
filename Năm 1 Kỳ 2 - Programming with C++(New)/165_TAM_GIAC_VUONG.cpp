#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

void input(std::unordered_set<unsigned long long> &A, int n)
{
    unsigned long long x;
    while (n--)
    {
        std::cin >> x;
        A.insert(x * x);
    }
}

bool solve(const std::unordered_set<unsigned long long> &A)
{
    for (auto it = A.begin(); it != A.end(); it++)
        for (auto jt = std::next(it); jt != A.end(); jt++)
            if (A.count(*it + *jt))
                return true;

    return false;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::unordered_set<unsigned long long> A;
        A.reserve(n);
        input(A, n);

        if (solve(A))
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << '\n';
    }

    return 0;
}