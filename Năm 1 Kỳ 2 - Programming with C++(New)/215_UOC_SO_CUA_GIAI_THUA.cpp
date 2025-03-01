#include <iostream>

int divide(int N, const int &k)
{
    int count = 0;
    while (N % k == 0)
    {
        ++count;
        N /= k;
    }
    return count;
}

int findX(const int &N, const int &p)
{
    int x = 0;
    for (int i = p; i <= N; i += p)
        x += divide(i, p);
    return x;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int N, p;
        std::cin >> N >> p;
        const int x = findX(N, p);
        std::cout << x << std::endl;
    }

    return 0;
}