#include <iostream>
#include <map>

void input(std::map<int, bool> &A, int n)
{
    int x;
    while (n--)
    {
        std::cin >> x;
        A[x] = 1;
    }
}

bool solve(std::map<int, bool> &A, const int x)
{
    auto it = A.lower_bound(x);
    while (it != A.end())
    {
        if (A[it->first - x])
            return true;
        it++;
    }

    return false;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n, x;
        std::cin >> n >> x;
        std::map<int, bool> A;
        input(A, n);

        if (solve(A, x))
            std::cout << 1;
        else
            std::cout << -1;
        std::cout << '\n';
    }

    return 0;
}