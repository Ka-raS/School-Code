#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = i + 1;

        do
        {
            for (const int &x : A)
                std::cout << x;
            std::cout << ' ';
        } while (std::next_permutation(A.begin(), A.end()));
        std::cout << '\n';
    }
    return 0;
}