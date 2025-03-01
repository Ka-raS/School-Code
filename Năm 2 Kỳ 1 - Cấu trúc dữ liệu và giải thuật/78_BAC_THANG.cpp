#include <iostream>
#include <vector>

int totalWaysToGoUpStair(const int stairHeight, const int maxReachPerStep)
{
    // ways[currentHeight] = total ways from currentHeight to the top of the stair
    std::vector<int> ways(stairHeight);
    const int modulus = 1e9 + 7;

    for (int currentHeight = stairHeight - 1; currentHeight >= 0; --currentHeight)
    {
        // if can reach the end of the stair right away
        if (currentHeight + maxReachPerStep >= stairHeight)
            ++ways[currentHeight];

        // ways[i] = ways[i + 1] + ways[i + 2] +...+ ways[i + max]
        for (int reach = 1; reach <= maxReachPerStep; ++reach)
        {
            const int nextHeight = currentHeight + reach;

            // reached the end of the stair, ways[the end] = 0
            if (nextHeight >= stairHeight)
                break;

            ways[currentHeight] += ways[nextHeight];
            ways[currentHeight] %= modulus;
        }
    }

    // total ways from height 0 to the top of the stair
    return ways[0];
}

void runProgram()
{
    int stairHeight, maxReachPerStep;
    std::cin >> stairHeight >> maxReachPerStep;
    std::cout << totalWaysToGoUpStair(stairHeight, maxReachPerStep) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}