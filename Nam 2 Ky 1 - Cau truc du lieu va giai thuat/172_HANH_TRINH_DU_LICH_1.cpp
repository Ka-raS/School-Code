#include <iostream>
#include <vector>

void input(std::vector<std::vector<int>>& costs) {
    size_t cityCount;
    std::cin >> cityCount;
    costs.resize(cityCount, std::vector<int>(cityCount));
    for (size_t i = 0; i < cityCount; ++i) {
        for (size_t j = 0; j < cityCount; ++j) {
            std::cin >> costs[i][j];
        }
    }
}

int findCost(const int city, const int mask, const std::vector<std::vector<int>>& costs,
             std::vector<std::vector<int>>& dp) {
    const int cityCount = costs.size();
    const int maskEnd = (1 << cityCount) - 1;

    const bool isCompletedPath = mask == maskEnd;
    if (isCompletedPath) {
        return 0;
    }

    const bool isVisited = dp[city][mask] != -1;
    if (isVisited) {
        return dp[city][mask];
    }

    int cost = INT32_MAX;
    for (int cityNext = 0; cityNext < cityCount; ++cityNext) {
        const bool isVisitedMask = (mask & (1 << cityNext)) != 0;
        if (isVisitedMask) {
            continue;
        }

        const int maskWithCityNext = mask | (1 << cityNext);
        const int costCurrent = costs[city][cityNext] + findCost(cityNext, maskWithCityNext, costs, dp);
        if (cost > costCurrent) {
            cost = costCurrent;
        }
    }
    dp[city][mask] = cost;
    return cost;
}

int minCost(const std::vector<std::vector<int>>& costs) {
    const int cityCount = costs.size();
    std::vector<std::vector<int>> dp(cityCount, std::vector<int>(1 << cityCount, -1));

    int cost = INT32_MAX;
    for (int cityBegin = 0; cityBegin < cityCount; ++cityBegin) {
        const int maskBegin = 0;
        const int costCurrent = findCost(cityBegin, maskBegin, costs, dp);
        if (cost > costCurrent) {
            cost = costCurrent;
        }
    }
    return cost;
}

void runProgram() {
    std::vector<std::vector<int>> costs;
    input(costs);
    std::cout << minCost(costs) << '\n';
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        runProgram();
    }
}