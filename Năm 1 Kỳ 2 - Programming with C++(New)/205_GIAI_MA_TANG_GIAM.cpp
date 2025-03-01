#include <iostream>
#include <string>
#include <vector>
#define NOTFOUND -1

int findPositionOfI(const std::string &ID, const int begin)
{
    for (int i = begin; i < ID.size(); ++i)
        if (ID[i] == 'I')
            return i;
    return NOTFOUND;
}

std::vector<int> convertArray(const std::string &ID)
{
    std::vector<int> Ans(ID.size() + 1);

    int value = 0;
    int previousPositionOfI = NOTFOUND;
    int currentPositionOfI = findPositionOfI(ID, 0);

    while (currentPositionOfI != NOTFOUND)
    {
        for (int i = currentPositionOfI; i > previousPositionOfI; --i)
            Ans[i] = ++value;

        previousPositionOfI = currentPositionOfI;
        currentPositionOfI = findPositionOfI(ID, currentPositionOfI + 1);
    }

    for (int i = Ans.size() - 1; i > previousPositionOfI; --i)
        Ans[i] = ++value;

    return Ans;
}

void outputArray(const std::vector<int> &Array)
{
    for (const int &element : Array)
        std::cout << element;
}

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int test = 0; test < testCases; ++test)
    {
        std::string ID;
        std::cin >> ID;
        const std::vector<int> Array = convertArray(ID);
        outputArray(Array);
        std::cout << std::endl;
    }

    return 0;
}