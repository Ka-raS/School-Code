#include <iostream>
#include <vector>
#include <unordered_map>

void input(std::vector<int> &array1, std::vector<int> &array2)
{
    size_t size1, size2;
    std::cin >> size1 >> size2;

    array1.resize(size1);
    array2.resize(size2);

    for (int &number : array1)
        std::cin >> number;
    for (int &number : array2)
        std::cin >> number;
}

// return sum of pair.second that satisfies pair.first < down || pair.first > up
long long count2(const std::unordered_map<int, int> &map2, const int down, const int up)
{
    long long count = 0;

    for (const std::pair<int, int> &pair2 : map2)
    {
        const int number2 = pair2.first;
        const int count2 = pair2.second;

        if (number2 < down || number2 > up)
            count += count2;
    }

    return count;
}

// return pairs of {array1[i], array2[j]} that satisfies (array1[i] ^ array2[j]) > (array2[j] ^ array1[i])
long long countValidPairs(const std::vector<int> &array1, const std::vector<int> &array2)
{
    std::unordered_map<int, int> map1, map2;

    for (const int number1 : array1)
        ++map1[number1];
    for (const int number2 : array2)
        ++map2[number2];

    long long count = 0;

    for (const std::pair<int, int> pair1 : map1)
    {
        const int number1 = pair1.first;
        const int count1 = pair1.second;

        switch (number1)
        {
        case 0: // 0 pair satisfies
            continue;

        case 1: // only number2 = 0 satisfies
            count += count1 * map2.at(0);
            break;

        case 2:
            count += count1 * count2(map2, 2, 4);
            break;

        case 3:
            count += count1 * count2(map2, 3, 3);
            break;

        default:
            count += count1 * count2(map2, 2, number1);
            break;
        }
    }

    return count;
}

void runProgram()
{
    std::vector<int> array1, array2;
    input(array1, array2);
    std::cout << countValidPairs(array1, array2) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}