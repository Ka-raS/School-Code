#include <bits/stdc++.h>

struct Coordinate {
    int y;
    int x;
};

void input();
void flagAllOnes();
void convert();
void output();
    
int i, j;
int rows, cols;
std::vector< Coordinate > flag;
std::vector< std::vector<int> > A(100, std::vector<int>(100));

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        input();
        flagAllOnes();
        convert();
        output();

        flag.clear();
    }

    return 0;
}

void input() {
    std::cin >> rows >> cols;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            std::cin >> A[i][j];
}

void flagAllOnes() {
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (A[i][j])
                flag.push_back({i, j});
}

void convert() {
    int length = flag.size();

    for (i = 0; i < length; i++) {
        for (j = 0; j < rows; j++)
            A[j][flag[i].x] = 1;

        for (j = 0; j < cols; j++)
            A[flag[i].y][j] = 1;
    }
}

void output() {
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            std::cout << A[i][j] << ' ';

        std::cout << '\n';
    }
}