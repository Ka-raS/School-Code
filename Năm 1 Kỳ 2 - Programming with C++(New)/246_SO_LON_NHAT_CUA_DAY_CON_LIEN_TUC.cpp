#include <bits/stdc++.h>

void input(std::vector<int> &A, int &n, int &k)
{
    std::cin >> n >> k;
    A.resize(n);

    for (int &x : A)
        std::cin >> x;
}

struct Element
{
    int value;
    int index;
};

Element findMax(const std::vector<int> &A, const int start, const int end)
{
    Element max;
    max.index = end;
    max.value = A[end];

    for (int i = end - 1; i >= start; i--)
        if (max.value < A[i])
        {
            max.index = i;
            max.value = A[i];
        }

    return max;
}

std::vector<int> findMaxElements(const std::vector<int> &A, const int n, const int k)
{
    std::vector<int> Ans;

    Element max = findMax(A, 0, k - 1);
    Ans.push_back(max.value);

    for (int i = k; i < n; i++)
    {
        if (max.value <= A[i] && max.index >= i - k)
        {
            max.index = i;
            max.value = A[i];
        }
        else if (max.index == i - k)
            max = findMax(A, i - k + 1, i);

        Ans.push_back(max.value);
    }

    return Ans;
}

void output(const std::vector<int> &A)
{
    for (int x : A)
        std::cout << x << ' ';
    std::cout << '\n';
}

int main()
{
    int T;
    std::cin >> T;

    int n, k;
    std::vector<int> A;

    while (T--)
    {
        input(A, n, k);
        std::vector<int> maxElements = findMaxElements(A, n, k);
        output(maxElements);
    }

    return 0;
}