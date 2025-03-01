#include <iostream>
#include <unordered_set>
#include <queue>
#include <set>

std::queue<std::pair<std::string, std::unordered_set<char>>> assignFirstQueueElements(const int digits)
{
    std::unordered_set<char> unusedDigits;

    for (char c = '1'; c <= digits + '0'; ++c)
        unusedDigits.insert(c);

    std::queue<std::pair<std::string, std::unordered_set<char>>> queue;

    for (int c = '1'; c <= digits + '0'; ++c)
    {
        unusedDigits.erase(c);
        queue.push({std::string(1, c), unusedDigits});
        unusedDigits.insert(c);
    }

    return queue;
}

std::set<std::string> findDistanceNumbers(const int digits)
{
    std::set<std::string> distanceNumbers;

    std::queue<std::pair<std::string, std::unordered_set<char>>> queue = assignFirstQueueElements(digits);

    while (!queue.empty())
    {
        std::string number = queue.front().first;
        std::unordered_set<char> unusedDigits = queue.front().second;

        if (number.size() == digits)
            distanceNumbers.insert(number);
        else
        {
            for (const char digit : queue.front().second) // unusedDigits
            {
                if (std::abs(digit - number.back()) == 1)
                    continue;

                number.push_back(digit);
                unusedDigits.erase(digit);

                queue.push({number, unusedDigits});

                number.pop_back();
                unusedDigits.insert(digit);
            }
        }

        queue.pop();
    }

    return distanceNumbers;
}

void printDistanceNumber(const int digits)
{
    const std::set<std::string> distanceNumbers = findDistanceNumbers(digits);

    for (const std::string &number : distanceNumbers)
        std::cout << number << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        int digits;
        std::cin >> digits;
        printDistanceNumber(digits);
    }
}