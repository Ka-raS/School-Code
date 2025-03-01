#include <iostream>
#include <queue>
#define SIZE 1000

struct Point
{
    int rowIndex;
    int columnIndex;
    int distance;
};

void input(bool Matrix[SIZE][SIZE], int &rows, int &columns, Point &Source, Point &Destination)
{
    std::cin >> rows >> columns;
    std::cin >> Source.rowIndex >> Source.columnIndex;
    std::cin >> Destination.rowIndex >> Destination.columnIndex;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
        {
            int value;
            std::cin >> value;
            Matrix[i][j] = value;
        }
}

const int x[] = {1, -1, 0, 0};
const int y[] = {0, 0, -1, 1};
int minDistance(bool Matrix[SIZE][SIZE], const int rows, const int columns, const Point &Source, const Point &Destination)
{
    const auto isValid = [&](const Point &point) -> bool
    {
        const int i = point.rowIndex;
        const int j = point.columnIndex;
        return i >= 0 && j >= 0 && i < rows && j < columns && Matrix[i][j];
    };

    if (!isValid(Source) || !isValid(Destination))
        return -1;

    std::queue<Point> Queue;
    {
        const int i = Source.rowIndex;
        const int j = Source.columnIndex;
        Queue.push({i, j, 0});
        Matrix[i][j] = 0;
    }

    while (!Queue.empty())
    {
        const Point point = Queue.front();
        const int i = point.rowIndex;
        const int j = point.columnIndex;
        const int d = point.distance;

        Queue.pop();
        for (int k = 0; k < 4; ++k)
        {
            const int iNext = i + x[k];
            const int jNext = j + y[k];
            const int dNext = d + 1;
            const Point pointNext = {iNext, jNext, dNext};

            if (iNext == Destination.rowIndex && jNext == Destination.columnIndex)
                return dNext;

            if (isValid(pointNext))
            {
                Queue.push(pointNext);
                Matrix[iNext][jNext] = 0;
            }
        }
    }

    return -1;
}

int main()
{
    int rows, columns;
    Point Source, Destination;
    bool Matrix[SIZE][SIZE];

    int testCases;
    std::cin >> testCases;
    for (int test = 0; test < testCases; ++test)
    {
        input(Matrix, rows, columns, Source, Destination);
        std::cout << minDistance(Matrix, rows, columns, Source, Destination) << std::endl;
    }

    return 0;
}