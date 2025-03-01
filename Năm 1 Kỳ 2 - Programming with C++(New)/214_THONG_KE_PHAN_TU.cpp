#include <bits/stdc++.h>

const int MAXLIST = 10000;

struct list
{
    int n;
    int nodes[MAXLIST];
};

void input(list &ds)
{
    int x;
    ds.n = 0;

    while (std::cin >> x)
    {
        if (std::cin.eof())
            break;

        ds.nodes[ds.n] = x;
        ds.n++;
    }
}

int count(const int num, list ds, std::vector<bool> &counted)
{
    int count = 0;

    for (size_t i = num; i < ds.n; i++)
        if (counted[i] == false && ds.nodes[i] == ds.nodes[num])
        {
            count++;
            counted[i] = true;
        }

    return count;
}

void output(const list ds, std::vector<bool> counted)
{
    counted.resize(ds.n);

    for (size_t i = 0; i < ds.n; i++)
        if (counted[i] == false)
            std::cout << ds.nodes[i] << ' ' << count(i, ds, counted) << '\n';
}

int main()
{
    list ds;
    std::vector<bool> counted;

    input(ds);
    output(ds, counted);

    return 0;
}