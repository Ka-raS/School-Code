#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const std::string &A, const std::string &B)
{
    return (A + B) > (B + A);
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<std::string> A(n);
        for (std::string &x : A)
            std::cin >> x;

        std::sort(A.begin(), A.end(), cmp);
        for (const std::string &x : A)
            std::cout << x;
        std::cout << '\n';
    }

    return 0;
}