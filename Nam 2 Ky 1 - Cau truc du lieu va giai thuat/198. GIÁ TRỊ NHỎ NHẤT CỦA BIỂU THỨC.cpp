#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<long long> &vec1, std::vector<long long> &vec2)
{
    size_t size;
    std::cin >> size;
    vec1.resize(size);
    vec2.resize(size);
    for (long long &num : vec1)
        std::cin >> num;
    for (long long &num : vec2)
        std::cin >> num;
}

long long minProductSums(std::vector<long long> &vec1, std::vector<long long> &vec2)
{
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end(), std::greater<long long>());
    long long sum = 0;
    for (size_t i = 0, n = vec1.size(); i < n; ++i)
        sum += vec1[i] * vec2[i];
    return sum;
}

void runProgram()
{
    std::vector<long long> vec1, vec2;
    input(vec1, vec2);
    std::cout << minProductSums(vec1, vec2) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}