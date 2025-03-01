#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int> &A, int n)
{
    int i;
    while (n--)
    {
        std::cin >> i;
        A[i]++;
    }
}

int find_result(const std::vector<int> &A, const int n, const int k, const int b)
{
    int count = 0;
    for (int i = 0; i < k; i++)
        if (A[i])
            count++;

    int result = count;
    for (int i = k; i < n; i++)
    {
        if (A[i - k])
            count--;
        if (A[i])
            count++;
        result = std::min(result, count);
    }

    return result;
}

int main()
{
    int n, k, b;
    std::cin >> n >> k >> b;
    std::vector<int> A(n);
    input(A, b);

    int result = find_result(A, n, k, b);
    std::cout << result;

    return 0;
}