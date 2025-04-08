#include <bits/stdc++.h>
using namespace std;

bool check(const string &A)
{
    int n = A.size();
    if (n == 1)
        return false;

    for (int i = 0; i < n / 2; i++)
        if (A[i] != A[n - i - 1])
            return false;
    return true;
}

vector<pair<string, int>> convert(const map<string, int> &M)
{
    vector<pair<string, int>> V;
    for (const auto &p : M)
        V.push_back(p);
    return V;
}

bool cmp(const pair<string, int> &A, const pair<string, int> &B)
{
    int n = A.first.size(),
        m = B.first.size();

    if (n < 20 && m < 20)
        return stoull(A.first) > stoull(B.first);
    if (n == m)
        return A.first > B.first;
    return n > m;
}

int main()
{
    string N;
    map<string, int> M;

    while (cin >> N)
        if (check(N))
            M[N]++;

    vector<pair<string, int>> V = convert(M);
    sort(V.begin(), V.end(), cmp);

    for (const auto &p : V)
        cout << p.first << ' ' << p.second << '\n';

    return 0;
}