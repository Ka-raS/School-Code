#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

class Maze
{
public:
    void input();
    void solve();
    void output_solutions() const;

private:
    std::vector<std::vector<int>> map;
    std::vector<std::string> solutions;
};

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        Maze maze;
        maze.input();
        maze.solve();
        maze.output_solutions();
    }
}

void Maze::input()
{
    std::size_t size;
    std::cin >> size;
    this->map.resize(size, std::vector<int>(size));

    for (std::vector<int> &row : this->map)
        for (int &num : row)
            std::cin >> num;
}

void Maze::solve()
{
    std::queue<std::tuple<std::size_t, std::size_t, std::string>> paths;
    if (this->map[0][0] == 1)
        paths.emplace(std::make_tuple(0, 0, ""));

    while (!paths.empty())
    {
        const std::size_t row = std::get<0>(paths.front());
        const std::size_t column = std::get<1>(paths.front());
        const std::string current_path = std::get<2>(paths.front());
        paths.pop();

        if (row == this->map.size() - 1 && column == this->map.size() - 1)
            this->solutions.push_back(current_path);
        else
        {
            if (row < this->map.size() - 1 && this->map[row + 1][column] == 1)
                paths.push(std::make_tuple(row + 1, column, current_path + 'D'));

            if (column < this->map.size() - 1 && this->map[row][column + 1] == 1)
                paths.push(std::make_tuple(row, column + 1, current_path + 'R'));
        }
    }
}

void Maze::output_solutions() const
{
    if (this->solutions.empty())
    {
        std::cout << -1 << std::endl;
        return;
    }

    for (const std::string &solution : this->solutions)
        std::cout << solution << ' ';
    std::cout << std::endl;
}