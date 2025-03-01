#include <iostream>
#include <vector>

void input(std::vector<std::vector<int>> &board)
{
    for (std::vector<int> &row : board)
    {
        for (int &square : row)
        {
            std::cin >> square;
        }
    }
}

bool isValid(const std::vector<size_t> &queenCol, const size_t col)
{
    const size_t row = queenCol.size();
    for (size_t r = 0; r < row; ++r)
    {
        const size_t c = queenCol[r];
        if (c == col || row + col == r + c || row + c == r + col)
        {
            return false;
        }
    }

    return true;
}

void recursion(const int sum, int &answer, std::vector<size_t> &queenCol, const std::vector<std::vector<int>> &board)
{
    if (answer < sum && queenCol.size() == 8)
    {
        answer = sum;
    }

    for (size_t c = 0; c < 8; ++c)
    {
        if (!isValid(queenCol, c))
        {
            continue;
        }

        const size_t r = queenCol.size();
        queenCol.emplace_back(c);
        recursion(sum + board[r][c], answer, queenCol, board);
        queenCol.pop_back();
    }
};

int maxPoint(const std::vector<std::vector<int>> &board)
{
    int answer = INT32_MIN;
    std::vector<size_t> queenCol;
    queenCol.reserve(8);
    recursion(0, answer, queenCol, board);
    return answer;
}

void runProgram()
{
    std::vector<std::vector<int>> board(8, std::vector<int>(8));
    input(board);
    std::cout << maxPoint(board) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        runProgram();
    }
}