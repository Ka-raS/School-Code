#include <iostream>
#include <vector>
#include <algorithm>

struct Time
{
private:
    int second;
    int minute;
    int hour;

public:
    friend std::istream &operator>>(std::istream &input, Time &A)
    {
        input >> A.hour >> A.minute >> A.second;
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Time &A)
    {
        output << A.hour << ' '
               << A.minute << ' '
               << A.second;
        return output;
    }

    const bool operator<(const Time &other) const
    {
        if (hour != other.hour)
            return hour < other.hour;
        if (minute != other.minute)
            return minute < other.minute;
        return second < other.second;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<Time> A(n);

    for (Time &X : A)
        std::cin >> X;

    std::sort(A.begin(), A.end());

    for (const Time &X : A)
        std::cout << X << '\n';

    return 0;
}