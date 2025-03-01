#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> A(n);
        for (int &x : A)
            std::cin >> x;
        std::sort(A.begin(), A.end());
        std::cout << A[k - 1] << '\n';
    }

    return 0;
}