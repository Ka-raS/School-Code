#include <iostream>
#include <vector>
#include <queue>
#include <set>

void input(std::vector<int> &array);
void printSubArray(const std::vector<int> &array);

int main()
{
    std::vector<int> array;
    input(array);
    printSubArray(array);
}

void input(std::vector<int> &array)
{
    std::size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &num : array)
        std::cin >> num;
}

struct SubArray
{
    std::string data;
    int lastNum;
    std::size_t lastNumIdx;
};

void printSubArray(const std::vector<int> &array)
{
    std::queue<SubArray> queue;
    for (std::size_t i = 0; i < array.size(); ++i)
    {
        SubArray subArray;
        subArray.data = std::to_string(array[i]);
        subArray.lastNum = array[i];
        subArray.lastNumIdx = i;

        queue.push(subArray);
    }

    std::set<std::string> subArrays;

    while (!queue.empty())
    {
        SubArray *current = &queue.front();

        for (std::size_t i = current->lastNumIdx + 1; i < array.size(); ++i)
            if (array[i] > current->lastNum)
            {
                SubArray nextSubArray;
                nextSubArray.data = current->data + ' ' + std::to_string(array[i]);
                nextSubArray.lastNum = array[i];
                nextSubArray.lastNumIdx = i;

                subArrays.insert(nextSubArray.data);
                queue.push(nextSubArray);
            }

        queue.pop();
    }

    for (const std::string &subArray : subArrays)
        std::cout << subArray << std::endl;
}