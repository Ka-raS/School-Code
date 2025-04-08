//  Một bảng được sắp xếp bằng các số {1, 2, 3, 4, 5, 6}
//  Ví dụ:  |1|2|3|
//          |4|5|6|
//  Có 2 cách quay bảng
//      Cách 1: Quay theo chiều kim đồng hồ hình vuông: |1|2|
//                                                      |4|5|
//              Kết quả: |4|1|3|
//                       |5|2|6|
//
//      Cách 2: Quay theo chiều kim đồng hồ hình vuông: |2|3|
//                                                      |5|6|
//              Kết quả: |1|5|2|
//                       |4|6|3|
//
//  Tìm số bước quay ít nhất để chuyển bảng Source thành bảng Target

#include <iostream>
#include <array>
#include <queue>

class Board
{
public:
    int minSteps(const Board &) const;
    friend std::istream &operator>>(std::istream &, Board &);

private:
    bool operator==(const Board &) const;
    Board leftRotate() const;
    Board rightRotate() const;

private:
    std::array<int, 6> data;
};

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        Board Source, Target;
        std::cin >> Source >> Target;
        std::cout << Source.minSteps(Target) << std::endl;
    }
}

int Board::minSteps(const Board &T) const
{
    std::queue<std::pair<Board, int>> queue;
    queue.push({*this, 0});

    while (!queue.empty())
    {
        const Board B = queue.front().first;
        const int rotations = queue.front().second;
        queue.pop();

        if (B == T)
            return rotations;

        queue.push({B.leftRotate(), rotations + 1});
        queue.push({B.rightRotate(), rotations + 1});
    }
}

Board Board::leftRotate() const
{
    Board res = *this;
    std::array<int, 6> &A = res.data;
    const int tmp = A[0];
    A[0] = A[3];
    A[3] = A[4];
    A[4] = A[1];
    A[1] = tmp;
    return res;
}

Board Board::rightRotate() const
{
    Board res = *this;
    std::array<int, 6> &A = res.data;
    const int tmp = A[1];
    A[1] = A[4];
    A[4] = A[5];
    A[5] = A[2];
    A[2] = tmp;
    return res;
}

std::istream &operator>>(std::istream &in, Board &B)
{
    for (int &n : B.data)
        in >> n;
    return in;
}

bool Board::operator==(const Board &other) const
{
    return this->data == other.data;
}