#include <bits/stdc++.h>

void swap(std::string &X, std::string &Y)
{
    std::string tmp = X;
    X = Y;
    Y = tmp;
}

std::string find_sum(const std::string &X, const std::string &Y)
{
    bool remainder = 0;
    std::string sum = X;
    int size_gap = X.size() - Y.size(),
        i = X.size() - 1;

    while (i >= size_gap)
    {
        int digit = X[i] + Y[i - size_gap] - 2 * '0' + remainder;
        if (digit >= 10)
        {
            digit -= 10;
            remainder = 1;
        }
        else
            remainder = 0;
        sum[i] = digit + '0';
        i--;
    }

    while (remainder && i >= 0)
    {
        if (sum[i] == '9')
        {
            remainder = 1;
            sum[i] = '0';
        }
        else
        {
            remainder = 0;
            sum[i]++;
        }
        i--;
    }

    if (remainder && i == -1)
        sum.insert(sum.begin(), '1');

    return sum;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::string X, Y;
        std::cin >> X >> Y;

        // ensure that X is >= Y
        if (X.size() < Y.size())
            swap(X, Y);
        else if (X.size() == Y.size() && X[0] < Y[0])
            swap(X, Y);

        std::string sum = find_sum(X, Y);
        std::cout << sum << '\n';
    }

    return 0;
}