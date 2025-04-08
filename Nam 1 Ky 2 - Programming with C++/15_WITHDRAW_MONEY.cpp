#include<iostream>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    int money;
    int coinValue[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

    while (testCases--) {
        cin >> money;

        int coins = 0;

        for (int i = 9; money != 0; i--)
            while (money - coinValue[i] >= 0) {
                money -= coinValue[i];
                coins++;
            }

        cout << coins << endl;
    }

    return 0;
}