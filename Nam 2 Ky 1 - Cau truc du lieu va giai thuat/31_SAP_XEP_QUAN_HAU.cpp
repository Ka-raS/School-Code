#include <iostream>
#include <vector>

void mark_new_squares_controlled(std::vector<std::vector<bool>> &board,
                                 const std::size_t rank_begin, const std::size_t file_begin)
{
    for (std::size_t i = 0; i < board.size(); ++i)
        board[i][file_begin] = true;

    for (std::size_t j = 0; j < board.size(); ++j)
        board[rank_begin][j] = true;

    // for (int i = rank_begin, j = file_begin; i >= 0 && j >= 0; --i, --j)
    //     board[i][j] = true;

    // for (std::size_t i = rank_begin, j = file_begin; i < board.size() && j < board.size(); ++i, ++j)
    //     board[i][j] = true;

    // for (int i = rank_begin, j = file_begin; i >= 0 && j < board.size(); --i, ++j)
    //     board[i][j] = true;

    // for (int i = rank_begin, j = file_begin; i < board.size() && j >= 0; ++i, --j)
    //     board[i][j] = true;
}

void find_all_positions(int &positions, std::vector<std::vector<bool>> board,
                        const int queens, const int queens_target,
                        std::size_t rank_begin, std::size_t file_begin)
{
    mark_new_squares_controlled(board, rank_begin, file_begin);
    if (queens == queens_target)
    {
        ++positions;
        return;
    }

    std::cout << "queens = " << queens << '\n';
    for (auto v : board)
    {
        for (auto b : v)
            std::cout << b << ' ';
        std::cout << '\n';
    }

    for (std::size_t i = rank_begin + 1; i < board.size(); ++i)
        for (std::size_t j = 0; j < board.size(); ++j)
        {
            if (board[i][j] == false) // if square is not controlled
            {
                find_all_positions(positions, board, queens + 1, queens_target, i, j); // put new queen
            }
        }
}

// number of positions that n queens can't see the others on a n*n chessboard
int count_positions(const int n)
{
    // check if the square is controlled by any queen
    const std::vector<std::vector<bool>> starting_board(n, std::vector<bool>(n, false));

    int positions = 0;

    for (std::size_t i = 0; i < n; ++i)
        for (std::size_t j = 0; j < n; ++j)
            find_all_positions(positions, starting_board, 1, n, 0, 0);

    return positions;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        int n;
        std::cin >> n;
        std::cout << count_positions(n) << std::endl;
    }
}