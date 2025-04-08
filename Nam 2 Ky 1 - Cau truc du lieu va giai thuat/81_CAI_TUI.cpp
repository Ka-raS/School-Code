#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct Item
{
    int volumn;
    int value;
    double ratio;
};

void input(std::vector<Item> &items, int &bagVolumn)
{
    size_t itemsSize;
    std::cin >> itemsSize >> bagVolumn;
    items.resize(itemsSize);

    for (Item &item : items)
        std::cin >> item.volumn;

    for (Item &item : items)
        std::cin >> item.value;
}

void sortValueToVolumnDescending(std::vector<Item> &items)
{
    auto compare = [](const Item &item1, const Item &item2) -> bool
    {
        return item1.ratio > item2.ratio;
    };
    std::sort(items.begin(), items.end(), compare);
}

struct Node
{
    size_t index;
    int value;
    int volumn;
};

int valueBound(const Node &node, const std::vector<Item> &items, const int bagVolumn)
{
    size_t i = node.index;
    int value = node.value;
    int volumn = node.volumn;

    if (volumn >= bagVolumn)
        return 0;

    while (i < items.size() && volumn + items[i].volumn <= bagVolumn)
    {
        value += items[i].value;
        volumn += items[i].volumn;
        ++i;
    }

    if (i < items.size())
        value += (bagVolumn - volumn) * items[i].ratio;

    return value;
}

int maxValueBagCanFit(std::vector<Item> items, const int bagVolumn)
{
    // Branch and Bound Algorithm

    for (Item &item : items)
        item.ratio = (double)item.value / item.volumn;

    sortValueToVolumnDescending(items);

    int maxValue = INT32_MIN;
    std::stack<Node> stack;
    stack.push({0, 0, 0});

    while (stack.empty() == false)
    {
        const Node current = stack.top();
        stack.pop();

        if (current.index >= items.size())
            continue;

        const Node next = {
            current.index + 1,
            current.value + items[current.index].value,
            current.volumn + items[current.index].volumn,
        };

        if (next.value > maxValue && next.volumn <= bagVolumn)
            maxValue = next.value;

        const Node test1 = {
            next.index,
            current.value,
            current.volumn,
        };
        const Node &test2 = next;

        if (valueBound(test1, items, bagVolumn) > maxValue)
            stack.push(test1);
        if (valueBound(test2, items, bagVolumn) > maxValue)
            stack.push(test2);
    }

    return maxValue;
}

void runProgram()
{
    std::vector<Item> items;
    int bagVolumn;

    input(items, bagVolumn);
    std::cout << maxValueBagCanFit(items, bagVolumn) << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}