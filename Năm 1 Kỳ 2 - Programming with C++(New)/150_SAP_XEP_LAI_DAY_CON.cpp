#include <bits/stdc++.h>

void input(std::multiset<int> &set_A, std::vector<int> &vector_A)
{
    for (int &x : vector_A)
    {
        std::cin >> x;
        set_A.insert(x);
    }
}

int first(const std::multiset<int> &set_A, const std::vector<int> &vector_A)
{
    int i = 0;
    for (const int x : set_A)
    {
        if (x != vector_A[i])
            return i + 1;
        i++;
    }
    return 0;
}

int last(const std::multiset<int> &set_A, const std::vector<int> &vector_A, int i)
{
    std::set<int>::reverse_iterator it = set_A.rbegin();
    while (i--)
    {
        if (*it != vector_A[i])
            return i + 1;
        it++;
    }

    return 0;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> vector_A(n);
        std::multiset<int> set_A;
        input(set_A, vector_A);

        std::cout << first(set_A, vector_A) << ' ' << last(set_A, vector_A, n) << '\n';
    }

    return 0;
}