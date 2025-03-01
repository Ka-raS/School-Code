#include <bits/stdc++.h>

int main() {
    int testCases;
    std::cin >> testCases;

    int length, numQuests;
    int left, right;
    std::vector<int> array;

    int i;
    long long sum;

    while (testCases--) {
        std::cin >> length >> numQuests;

        array.resize(length);

        for (i = 0; i < length; i++)
            std::cin >> array.at(i);

        while (numQuests--) {
            std::cin >> left >> right;

            sum = 0;

            for (i = left - 1; i < right; i++)
                sum += array.at(i);

            std::cout << sum << '\n';
        }

        array.clear();
    }

    return 0;
}