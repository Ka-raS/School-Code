#include <bits/stdc++.h>
using namespace std;

int convert(const string &num)
{
    if (num.size() > 10)
        return 0;
    for (const char &c : num)
        if (c < '0' || c > '9')
            return 0;
    long long ans = stoll(num);
    if (ans > INT_MAX)
        return 0;
    return static_cast<int>(ans);
}

int main()
{
    ifstream infile("DATA.in");
    string line, buf;
    long long sum = 0;
    while (getline(infile, line))
    {
        stringstream ss(line);
        while (ss >> buf)
            sum += convert(buf);
    }
    cout << sum;
    return 0;
}