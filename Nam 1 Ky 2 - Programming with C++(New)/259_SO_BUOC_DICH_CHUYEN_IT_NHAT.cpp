#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int>&);
int findMin(const std::vector<int>&, const size_t, const size_t);

int minMoves(const std::vector<int>& Array) {
    const size_t n = Array.size();
    std::vector<int> Moves(n);


    for (int i = n - 2; i >= 0; --i) {
        if (Array[i] == 0) // game over
            Moves[i] = INT32_MAX;
        else if (Array[i] >= n - i - 1) // enough steps to reach the end
            Moves[i] = 1;
        else {
            const size_t begin = i + 1;
            const size_t end = std::min(n, (size_t)Array[i] + i + 1);
            const int min = findMin(Moves, begin, end);
            if (min != INT32_MAX)
                Moves[i] = min + 1;
            else
                Moves[i] = INT32_MAX;
        }
    }
    return Moves[0];
}

int main() {
    int testCases;
    std::cin >> testCases;
    for (int test = 0; test < testCases; ++test) {
        std::vector<int> Array;
        input(Array);
        std::cout << minMoves(Array) << std::endl;
    }
    return 0;
}

int findMin(const std::vector<int>& Array, const size_t begin, const size_t end) {
    int ans = INT32_MAX;
    for (size_t i = begin; i < end; ++i)
        ans = std::min(ans, Array[i]);
    return ans;
}

void input(std::vector<int>& Array) {
    size_t size;
    std::cin >> size;
    Array.resize(size);
    for (int& num : Array)
        std::cin >> num;
}