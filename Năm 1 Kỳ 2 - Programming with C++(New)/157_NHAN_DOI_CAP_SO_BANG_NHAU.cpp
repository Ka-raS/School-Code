#include <iostream>
#include <vector>
#include <algorithm>

void inputVector(std::vector<int> &A)
{
    for (int &x : A)
        std::cin >> x;
}

void convert(std::vector<int> &A)
{
    for (int i = 1; i < A.size(); i++)
        if (A[i] == A[i - 1])
        {
            A[i - 1] *= 2;
            A[i] = 0;
        }
}

void outputVector(const std::vector<int> &A)
{
    for (const int x : A)
        if (x)
            std::cout << x << ' ';
    for (const int x : A)
        if (!x)
            std::cout << 0 << ' ';
    std::cout << '\n';
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
        inputVector(A);
        convert(A);
        outputVector(A);
    }

    return 0;
}