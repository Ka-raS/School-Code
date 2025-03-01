#include <iostream>
#include <iomanip>
#include <cmath>

class Point
{
public:
    double x;
    double y;

    friend std::istream &operator>>(std::istream &input, Point &point)
    {
        input >> point.x >> point.y;
        return input;
    }
};

double distance(const Point &M, const Point &N)
{
    const double x = std::pow(N.x - M.x, 2),
                 y = std::pow(N.y - M.y, 2);
    return std::sqrt(x + y);
}

bool is_valid(const double &a, const double &b, const double &c)
{
    if (a >= b + c)
        return false;
    if (b >= a + c)
        return false;
    if (c >= a + b)
        return false;
    return true;
}

double find_triangle_area(const double &a, const double &b, const double &c)
{
    const double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    int test_cases;
    std::cin >> test_cases;
    while (test_cases--)
    {
        Point A, B, C;
        std::cin >> A >> B >> C;

        const double side_a = distance(B, C),
                     side_b = distance(A, C),
                     side_c = distance(A, B);

        if (is_valid(side_a, side_b, side_c))
        {
            const double triangle_area = find_triangle_area(side_a, side_b, side_c),
                         radius = (side_a * side_b * side_c) / (4 * triangle_area),
                         circle_area = M_PI * radius * radius;
            std::cout << std::fixed << std::setprecision(3) << circle_area;
        }
        else
            std::cout << "INVALID";

        std::cout << '\n';
    }
    return 0;
}