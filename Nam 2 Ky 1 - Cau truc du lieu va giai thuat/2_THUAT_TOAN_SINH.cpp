#include <iostream>
#include <vector>

void output(const std::vector<bool> &Arr)
{
    for (bool n : Arr)
        std::cout << n << ' ';
    std::cout << std::endl;
}

int main()
{
    int len;
    std::cin >> len;
    std::vector<bool> Arr(len, 0);
    output(Arr);

    for (int i = len / 2; i < len; ++i)
    {
        std::fill(Arr.begin(), Arr.end(), 0);
        Arr[i] = Arr[len - 1 - i] = 1;
        output(Arr);

        for (int j = len / 2; j < i; ++j)
        {
            Arr[j] = Arr[len - 1 - j] = 1;
            output(Arr);
        }
    }
}