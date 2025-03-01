#include <iostream>
#include <algorithm>
#include <vector>

void output(const std::vector<int> &A, const int k, const int x)
{
    const std::vector<int>::const_iterator it = std::lower_bound(A.begin(), A.end(), x);
    int i = std::distance(A.begin(), it) - k / 2;

    for (int j = 0; j < k / 2; j++)
        std::cout << A[i++] << ' ';
    i++;
    for (int j = k / 2; j < k; j++)
        std::cout << A[i++] << ' ';
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int &val : A)
            std::cin >> val;
        int k, x;
        std::cin >> k >> x;
        output(A, k, x);
        std::cout << '\n';
    }

    return 0;
}