#include <iostream>
#include <algorithm>

long long ans(const int *A, const int n, const int k)
{
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        const int *j = std::lower_bound(A + i + 1, A + n, A[i] + k); // first element to >= *it + k
        const int elements = j - (A + i) - 1;                        // Number of elements between [A[i], *j)
        ans += elements;
    }

    return ans;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        int A[n];
        for (int &x : A)
            std::cin >> x;

        std::sort(A, A + n);
        std::cout << ans(A, n, k) << '\n';
    }

    return 0;
}