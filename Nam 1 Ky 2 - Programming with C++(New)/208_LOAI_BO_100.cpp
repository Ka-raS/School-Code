#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Char
{
    char val;
    int idx;
};

bool isContain100(const std::vector<Char> &A)
{
    const int n = A.size();
    if (n < 3)
        return false;

    if (A[n - 3].val != '1')
        return false;
    if (A[n - 2].val != '0')
        return false;
    if (A[n - 1].val != '0')
        return false;
    return true;
}

void remove100(std::vector<Char> &A) { A.erase(A.end() - 3, A.end()); }
std::string S;
int ans()
{
    int res = 0;
    std::vector<Char> A; // duplicate string S

    for (int i = 0; i < S.size(); ++i)
    {
        A.push_back({S[i], i});
        while (isContain100(A))
            remove100(A);

        const int subStrSize = i - A.back().idx;
        if (res < subStrSize)
            res = subStrSize;
    }

    return res;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::cin >> S;
        std::cout << ans() << std::endl;
    }

    return 0;
}