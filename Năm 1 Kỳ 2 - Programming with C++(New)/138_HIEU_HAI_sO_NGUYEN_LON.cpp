#include <bits/stdc++.h>

void swap(std::string &X, std::string &Y)
{
    std::string tmp = X;
    X = Y;
    Y = tmp;
}

std::string find_diff(const std::string &X, const std::string &Y)
{
    bool remainder = 0;
    std::string diff = X;
    int size_gap = X.size() - Y.size(),
        i = X.size() - 1;

    while (i >= size_gap)
    {
        int digit = X[i] - Y[i - size_gap] - remainder;
        if (digit < 0)
        {
            digit += 10;
            remainder = 1;
        }
        else
            remainder = 0;
        diff[i] = digit + '0';
        i--;
    }

    while (remainder) // i can't be less than 0 because X >= Y
    {
        if (diff[i] == '0')
        {
            remainder = 1;
            diff[i] = '9';
        }
        else
        {
            remainder = 0;
            diff[i]--;
        }
        i--;
    }

    return diff;
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

        std::string diff = find_diff(X, Y);
        std::cout << diff << '\n';
    }

    return 0;
}