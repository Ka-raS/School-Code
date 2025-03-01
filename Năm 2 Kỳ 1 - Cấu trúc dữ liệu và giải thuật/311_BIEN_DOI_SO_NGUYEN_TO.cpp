// Biến số nguyên tố có 4 chữ số Source thành số nguyên tố có 4 chữ số Target
// Phép biến đổi là làm thay đổi 1 chữ số của Source nhưng Source vẫn phải là số nguyên tố
// Tìm số phép biến đổi ít nhất

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

// Thuật toán Breadth First Search
class Solution
{
public:
    void startPreparation();
    int minSteps(const int, const int) const;

private:
    bool isPrime(const int) const;
    bool isOneDigitDifferent(int, int) const;

private:
    // Với n là số nguyên tố
    // primeList[n] trả về một vector các số nguyên tố,
    // primesList[n][i] khi so sánh với n thì có 1 chữ số khác nhau
    std::unordered_map<int, std::vector<int>> primesList;
};

int main()
{
    Solution solution;
    solution.startPreparation();

    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        int Source, Target;
        std::cin >> Source >> Target;
        std::cout << solution.minSteps(Source, Target) << std::endl;
    }
}

void Solution::startPreparation()
{
    // Lưu trữ các số nguyên có 4 chữ số
    std::vector<int> primes;
    for (int k = 1000; k <= 9999; ++k)
        if (isPrime(k))
            primes.push_back(k);

    // Điền vào this->primesList

    const std::size_t n = primes.size();

    for (std::size_t i = 0; i < n - 1; ++i)
        for (std::size_t j = i + 1; j < n; ++j)
        {
            const int a = primes[i];
            const int b = primes[j];

            if (isOneDigitDifferent(a, b))
            {
                this->primesList[a].push_back(b);
                this->primesList[b].push_back(a);
            }
        }
}

int Solution::minSteps(const int S, const int T) const
{
    // Với n là một số nguyên tố có 4 chữ số
    // steps[n] trả về số phép biến đổi từ S sang n
    std::unordered_map<int, int> steps;

    // Duyệt từng phần tử k trong danh sách this->primesList[S] để tìm T
    // Nếu không tìm thấy T thì duyệt tiếp danh sách this->primesList[k]
    std::queue<int> queue;

    queue.push(S);
    steps[S] = 0;

    while (!queue.empty())
    {
        const int k = queue.front();
        queue.pop();

        for (const int n : this->primesList.at(k))
            // Nếu chưa tồn tại phép biến đổi từ S sang n
            if (steps.count(n) == 0)
            {
                steps[n] = steps[k] + 1;
                if (n == T)
                    return steps[T];
                queue.push(n);
            }
    }

    return 0;
}

bool Solution::isPrime(const int n) const
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int k = 5; k * k <= n; k += 6)
        if (n % k == 0 || n % (k + 2) == 0)
            return false;

    return true;
}

bool Solution::isOneDigitDifferent(int m, int n) const
{
    int differences = 0;
    while (m > 0 && n > 0)
    {
        if (m % 10 != n % 10)
            ++differences;
        m /= 10;
        n /= 10;
    }
    return differences == 1;
}