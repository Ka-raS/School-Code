#include<iostream>
using namespace std;

int main() {
                            // 1    2    3    4    5    6    7    8    9   10   11   12   13   14   15
    char answer101[15][1] = {'A', 'B', 'B', 'A', 'D', 'C', 'C', 'A', 'B', 'D', 'C', 'C', 'A', 'B', 'D'};
    char answer102[15][1] = {'A', 'C', 'C', 'A', 'B', 'C', 'D', 'D', 'B', 'B', 'C', 'D', 'D', 'B', 'B'};

    int T;
    cin >> T;

    while (T--) {
        int quizSet;
        cin >> quizSet;
        
        char submission[15][1];
        for (int i = 0; i < 15; i++)
            cin >> submission[i][0];

        int point = 0;
        if (quizSet == 101) {
            for (int i = 0; i < 15; i++)
                if (submission[i][0] == answer101[i][0])
                    point++;
        }
        else if (quizSet == 102) {
            for (int i = 0; i < 15; i++)
                if (submission[i][0] == answer102[i][0])
                    point++;
        }

        printf("%.2f\n", (float)point / 15 * 10);
    }

    return 0;
}