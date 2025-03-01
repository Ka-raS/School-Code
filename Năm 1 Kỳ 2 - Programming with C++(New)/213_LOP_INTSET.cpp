#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream infile("DATA.in");
    int n, m;
    infile >> n >> m;
    unordered_map<int, int> A;
    set<int> B;
    while (n--)
    {
        int val;
        infile >> val;
        ++A[val];
    }
    while (m--)
    {
        int val;
        infile >> val;
        if (A[val])
            B.insert(val);
    }
    infile.close();
    for (int x : B)
        cout << x << ' ';
    return 0;
}