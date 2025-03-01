#include <iostream>
#include <vector>

int max(const std::vector<int> &A, const int n)
{
    std::vector<int> Ans;
    Ans.push_back(A[0]);

    for (size_t i = 1; i < n; ++i)
    {
        if (A[i] > Ans.back())
            Ans.push_back(A[i]);
        else
        {
            std::vector<int>::iterator low = std::lower_bound(Ans.begin(), Ans.end(), A[i]);
            *low = A[i];
        }
    }

    return Ans.size();
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
        for (int &x : A)
            std::cin >> x;
        std::cout << max(A, n) << '\n';
    }
    return 0;
}