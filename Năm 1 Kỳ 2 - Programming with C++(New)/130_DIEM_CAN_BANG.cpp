#include <bits/stdc++.h>

void input_array(std::vector<int> &array)
{
    for (int &value : array)
        std::cin >> value;
}

int find_sum_array(const std::vector<int> &array)
{
    int sum = 0;
    for (int value : array)
        sum += value;
    return sum;
}

int find_central_point(const std::vector<int> &array, const int len, const int sum_array)
{
    int sum_left = 0,
        sum_right = sum_array - array[0];
    if (sum_right == sum_left)
        return 1;

    for (int i = 1; i < len; i++)
    {
        sum_left += array[i - 1];
        sum_right -= array[i];

        if (sum_right == sum_left)
            return i + 1;
    }

    return -1;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        int len;
        std::cin >> len;
        std::vector<int> array(len);
        input_array(array);

        int sum_array = find_sum_array(array),
            position = find_central_point(array, len, sum_array);
        std::cout << position << '\n';
    }

    return 0;
}