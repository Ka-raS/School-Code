#include <iostream>
#include <vector>
#include <iomanip>

struct Point
{
    int x;
    int y;
};

double area(const std::vector<Point> &P)
{
    long long sum = 0;
    const size_t n = P.size();
    for (size_t i = 0; i < n - 1; ++i)
        sum += P[i].x * P[i + 1].y - P[i + 1].x * P[i].y;
    sum += P[n - 1].x * P[0].y - P[0].x * P[n - 1].y;
    if (sum < 0)
        sum = -sum;
    return 0.5 * sum;
}

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        int points;
        std::cin >> points;
        std::vector<Point> Shape(points);
        for (Point &p : Shape)
            std::cin >> p.x >> p.y;
        std::cout << std::fixed << std::setprecision(3)
                  << area(Shape) << std::endl;
    }
    return 0;
}