#include <iostream>
#include <array>

class FrogJump
{
public:
    void startPreparation()
    {
        this->ways = {1, 2, 4};
        for (size_t i = 3; i < 50; ++i)
            ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
    }

    long long waysToReachTheTop(const int mountainHeight)
    {
        return ways[mountainHeight - 1];
    }

private:
    std::array<long long, 50> ways;
};

int main()
{
    FrogJump solution;
    solution.startPreparation();

    int tests;
    std::cin >> tests;
    while (tests--)
    {
        int mountainHeight;
        std::cin >> mountainHeight;
        std::cout << solution.waysToReachTheTop(mountainHeight) << std::endl;
    }
}