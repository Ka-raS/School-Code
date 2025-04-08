#include <iostream>
#include <vector>

struct Cow
{
    int weight;
};

void input(std::vector<Cow> &cows)
{
    size_t numberOfCows;
    std::cin >> numberOfCows;
    cows.resize(numberOfCows);
    for (Cow &cow : cows)
        std::cin >> cow.weight;
}

int maxWeightTruckCanCarry(const std::vector<Cow> &cows, const int truckPayloadCapacity)
{
    // weight[value] = the max weight of a group of cows that is <= value
    std::vector<int> weight(truckPayloadCapacity + 1, 0);

    for (const Cow &cow : cows)
        for (int weightCap = truckPayloadCapacity; weightCap >= cow.weight; --weightCap)
        {
            const int weightPrevious = weight[weightCap - cow.weight];
            const int weightAdded = weightPrevious + cow.weight;

            if (weight[weightCap] < weightAdded)
                weight[weightCap] = weightAdded;
        }

    // return  the max weight of a group of cows that is <= truckPayloadCapacity
    return weight[truckPayloadCapacity];
}

void runProgram()
{
    int truckPayloadCapacity;
    std::cin >> truckPayloadCapacity;

    std::vector<Cow> cows;
    input(cows);

    std::cout << maxWeightTruckCanCarry(cows, truckPayloadCapacity);
}

int main()
{
    runProgram();
}