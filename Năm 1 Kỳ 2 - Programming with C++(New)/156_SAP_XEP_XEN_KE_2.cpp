#include <iostream>
#include <vector>
#include <algorithm>

void inputVector(std::vector<int> &A)
{
    for (int &x : A)
        std::cin >> x;
}

std::vector<int> sorting(const std::vector<int> &A, const int n)
{
    std::vector<int> answer;
    answer.reserve(n);

    for (int i = 0; i < n / 2; i++)
    {
        answer.push_back(A[n - i - 1]);
        answer.push_back(A[i]);
    }

    if (n % 2)
        answer.push_back(A[n / 2]);
    return answer;
}

void outputVector(const std::vector<int> &A)
{
    for (const int x : A)
        std::cout << x << ' ';
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

        std::sort(A.begin(), A.end());
        A = sorting(A, n);

        outputVector(A);
    }

    return 0;
}