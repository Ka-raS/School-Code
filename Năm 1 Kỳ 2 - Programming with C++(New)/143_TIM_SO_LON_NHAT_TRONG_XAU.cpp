#include <bits/stdc++.h>
using namespace std;

long long func(const string &A)
{
    long long ans = 0;
    string n = "0";

    for (char c : A)
    {
        if (c >= '0' && c <= '9')
            n.push_back(c);
        else
        {
            ans = max(ans, stoll(n));
            n = "0";
        }
    }

    return max(ans, stoll(n));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string A;
        cin >> A;
        cout << func(A) << '\n';
    }

    return 0;
}