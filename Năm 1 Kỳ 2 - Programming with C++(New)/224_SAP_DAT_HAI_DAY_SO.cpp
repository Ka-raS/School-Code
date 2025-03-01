#include <bits/stdc++.h>

void input(std::vector<int> &A1, std::vector<int> &A2, int &n, int &m)
{
    std::cin >> n >> m;
    A1.resize(n);
    A2.resize(m);

    for (int &x : A1)
        std::cin >> x;
    for (int &x : A2)
        std::cin >> x;
}

int appears(std::vector<int> &A1, int A2, int n, std::vector<bool> &flag)
{
    size_t i = 0;
    while (A1[i] < A2 && i < n)
        i++;

    int counts = 0;
    while (A1[i] == A2 && i < n)
    {
        flag[i] = true;
        counts++;
        i++;
    }

    return counts;
}

std::vector<int> findAns(std::vector<int> &A1, std::vector<int> &A2, const int n)
{
    std::vector<int> Ans;
    std::vector<bool> flagA1(n);
    std::vector<bool> flagA2(1e5 + 1);

    for (int numA2 : A2)
        if (flagA2[numA2] == false)
        {
            flagA2[numA2] = true;
            int count = appears(A1, numA2, n, flagA1);

            for (size_t i = 0; i < count; i++)
                Ans.push_back(numA2);
        }

    for (size_t i = 0; i < n; i++)
        if (flagA1[i] == false)
            Ans.push_back(A1[i]);

    return Ans;
}

void output(std::vector<int> &A)
{
    for (int x : A)
        std::cout << x << ' ';
    std::cout << '\n';
}

int main()
{
    int T;
    std::cin >> T;

    int n, m;
    std::vector<int> A1, A2;

    while (T--)
    {
        input(A1, A2, n, m);
        std::sort(A1.begin(), A1.end());

        std::vector<int> Ans = findAns(A1, A2, n);
        output(Ans);
    }

    return 0;
}