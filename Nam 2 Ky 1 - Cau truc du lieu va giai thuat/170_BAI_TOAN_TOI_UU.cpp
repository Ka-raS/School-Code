#include <iostream>
#include <vector>

struct Item {
    size_t pos;
    int value;
    int weight;
    float ratio;
};

void input(std::vector<Item> &itemList, int &weightLimit) {
    size_t itemCount;
    std::cin >> itemCount >> weightLimit;
    itemList.resize(itemCount);

    for (Item &item : itemList) {
        std::cin >> item.value;
    }
    for (Item &item : itemList) {
        std::cin >> item.weight;
    }
}

void output(const int valueSum, const std::vector<bool> &selectedList) {
    std::cout << valueSum << '\n';
    for (const bool selected : selectedList) {
        std::cout << selected << ' ';
    }
}

std::pair<int, std::vector<bool>> knapsack(const std::vector<Item> &itemList, const int weightLimit) {
    std::vector<std::vector<int>> dp(itemList.size() + 1, std::vector<int>(weightLimit + 1, 0));

    for (size_t i = 1; i <= itemList.size(); ++i) {
        const int value = itemList[i - 1].value;
        const int weight = itemList[i - 1].weight;

        for (size_t w = 0; w <= weightLimit; ++w) {
            if (w >= weight) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weight] + value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int weight = weightLimit;
    std::vector<bool> selectedList(itemList.size(), false);

    for (size_t i = itemList.size(); i > 0; --i) {
        if (dp[i][weight] != dp[i - 1][weight]) {
            weight -= itemList[i - 1].weight;
            selectedList[i - 1] = true;
        }
    }

    return {dp[itemList.size()][weightLimit], selectedList};
}

void runProgram() {
    int weightLimit;
    std::vector<Item> itemList;
    input(itemList, weightLimit);

    const auto [valueSum, selectedList] = knapsack(itemList, weightLimit);
    output(valueSum, selectedList);
}

int main() {
    runProgram();
    return EXIT_SUCCESS;
}