#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

// return index of the lower bound element from the Array
size_t lower_bound_index(const std::vector<int> &Array, size_t begin, size_t end, const int value)
{
    while (begin < end)
    {
        const size_t middle = begin + (end - begin) / 2;
        if (Array[middle] < value)
            begin = middle + 1;
        else
            end = middle;
    }
    return begin;
}

// return index of the upper bound element from the Array
size_t upper_bound_index(const std::vector<int> &Array, size_t begin, size_t end, const int value)
{
    while (begin < end)
    {
        const size_t middle = begin + (end - begin) / 2;
        if (Array[middle] <= value)
            begin = middle + 1;
        else
            end = middle;
    }
    return begin;
}

// count pairs of (x, y) that satisfies xʸ > yˣ
int countPairs(const std::vector<int> &X, std::vector<int> &Y)
{
    // x = 0: xʸ > yˣ ⇔ y ∉ R
    // x = 1: xʸ > yˣ ⇔ y ∉ [1, +∞)
    // x = 2: xʸ > yˣ ⇔ y ∉ [2, 4]
    // x = 3: xʸ > yˣ ⇔ y ∉ {3}
    // x > 3: xʸ > yˣ ⇔ y ∉ [2, x]

    std::sort(Y.begin(), Y.end());

    // convert to map
    std::map<int, int> mapX;
    for (const int x : X)
        ++mapX[x];

    // store indexes of the lower bound element from vector Y
    // 3 lower bounds: 1, 2, 3
    std::unordered_map<int, size_t> lowerBounds;
    lowerBounds.reserve(3);

    // find lower bounds
    for (int i = 1; i <= 3; ++i)
        lowerBounds[i] = lower_bound_index(Y, lowerBounds[i - 1], Y.size(), i);

    // store indexes of the upper bound element from vector Y
    // upper bounds of 3, 4 and all X[i]
    std::unordered_map<int, size_t> upperBounds;
    upperBounds.reserve(X.size() + 2);

    // find upper bounds
    {
        upperBounds[3] = upper_bound_index(Y, lowerBounds[3], Y.size(), 3);
        upperBounds[4] = upper_bound_index(Y, upperBounds[3], Y.size(), 4);

        std::map<int, int>::iterator it = mapX.begin();
        upperBounds[it->first] = upper_bound_index(Y, 0, Y.size(), it->first);
        std::map<int, int>::iterator prevIt = it;

        while (++it != mapX.end())
        {
            const int currX = it->first;
            const size_t prevXIndex = upperBounds[prevIt->first];
            upperBounds[currX] = upper_bound_index(Y, prevXIndex, Y.size(), currX);
            prevIt = it;
        }
    }

    // return number of y that is satisfied with x
    const auto count = [&](const int x) -> int
    {
        // xʸ > yˣ ⇔ y = Y[i], i ∉ [begin, end)
        size_t begin, end;

        // find begin and end
        switch (x)
        {
        case 0:
            return 0;

        case 1:
            begin = lowerBounds[1];
            end = Y.size();
            break;

        case 2:
            begin = lowerBounds[2];
            end = upperBounds[4];
            break;

        case 3:
            begin = lowerBounds[3];
            end = upperBounds[3];
            break;

        default:
            begin = lowerBounds[2];
            end = upperBounds[x];
            break;
        }

        return Y.size() - (end - begin);
    };

    int result = 0;
    for (const std::pair<const int, int> &p : mapX)
        result += count(p.first) * p.second; // p.second for duplicates
    return result;
}

void startProgram()
{
    size_t Xsize, Ysize;
    std::cin >> Xsize >> Ysize;
    std::vector<int> X(Xsize), Y(Ysize);

    for (int &x : X)
        std::cin >> x;
    for (int &x : Y)
        std::cin >> x;

    std::cout << countPairs(X, Y) << std::endl;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
        startProgram();
    return 0;
}