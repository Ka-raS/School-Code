#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void input(std::vector<int> &numbers)
{
    size_t size;
    std::cin >> size;
    numbers.resize(size);
    for (int &number : numbers)
        std::cin >> number;
}

void print(const std::vector<int> &numbers)
{
    for (const int number : numbers)
        std::cout << number << ' ';
    std::cout << '\n';
}

bool isPrime(const int number)
{
    if (number <= 1)
        return false;
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;

    for (int divisor = 5; divisor * divisor <= number; divisor += 6)
        if (number % divisor == 0 || number % (divisor + 2) == 0)
            return false;
    return true;
}

void printSubArrays(const std::vector<int> &numbers)
{
    const size_t count = numbers.size();
    int sum = 0;
    std::vector<int> list;
    list.reserve(count);

    const std::function<void(const size_t)> recursion = [&](const size_t pos) -> void
    {
        if (isPrime(sum))
            print(list);

        for (size_t i = 0; i < pos; ++i)
        {
            sum += numbers[i];
            list.emplace_back(numbers[i]);
            recursion(i);
            list.pop_back();
            sum -= numbers[i];
        }
    };

    for (size_t i = 0; i < count; ++i)
    {
        sum += numbers[i];
        list.emplace_back(numbers[i]);
        recursion(i);
        list.pop_back();
        sum -= numbers[i];
    }
}

void runProgram()
{
    std::vector<int> numbers;
    input(numbers);
    std::sort(numbers.begin(), numbers.end());
    printSubArrays(numbers);
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}