#include <iostream>
#include <vector>
#include <algorithm>

void inputVector(std::vector<int> &A)
{
    for (int &x : A)
        std::cin >> x;
}

// find number of elements <= k
int find_total(const std::vector<int> &A, const int k)
{
    int count = 0;
    for (const int x : A)
        if (x <= k)
            count++;
    return count;
}

// find number of element needed to be moved
int find_move(const std::vector<int> &A, const int n, const int k, const int total)
{
    int count = 0;
    for (int i = 0; i < total; i++)
        if (A[i] <= k)
            count++;

    int result = count;
    for (int i = total; i < n; i++)
    {
        if (A[i - total] <= k)
            count--;
        if (A[i] <= k)
            count++;
        result = std::max(result, count);
    }
    return result;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> A(n);
        inputVector(A);

        const int total = find_total(A, k);
        const int move = find_move(A, n, k, total);
        const int answer = total - move;
        std::cout << answer << '\n';
    }
    return 0;
}