#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int> &vec)
{
    size_t size;
    std::cin >> size;
    vec.resize(size);
    for (int &num : vec)
        std::cin >> num;
}

int maxProduct(std::vector<int> vec)
{
    std::sort(vec.begin(), vec.end());

    const size_t n = vec.size();
    const std::initializer_list<int> products = {
        vec[0] * vec[1] * vec[n - 1],

        vec[n - 1] * vec[n - 2],

        vec[n - 1] * vec[n - 2] * vec[n - 3],
    };

    return std::max(products);
}

void runProgram()
{
    std::vector<int> vec;
    input(vec);
    std::cout << maxProduct(vec);
}

int main()
{
    runProgram();
}