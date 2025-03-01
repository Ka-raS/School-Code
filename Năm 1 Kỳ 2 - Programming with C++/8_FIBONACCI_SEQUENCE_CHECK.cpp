#include<iostream>
#include<cmath>
using namespace std;

bool isPerfectSquare(int x) {
    int root = sqrt(x);
    return root * root == x;
}

bool isFibonacci(int n) {
    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int length;
        cin >> length;

        int array[length];

        for (int i = 0; i < length; i++) {
            cin >> array[i];
            if (isFibonacci(array[i])) {
                cout << array[i];
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}