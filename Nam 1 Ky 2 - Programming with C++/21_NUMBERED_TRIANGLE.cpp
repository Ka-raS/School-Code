#include <iostream>
using namespace std;

int main() {
    int height;
    cin >> height;
    
    for (int row = 1; row <= height; row++) {
        for (int value = 1; value < 2 * row; value++)
            cout << value;
        cout << endl;    
    }
    
    return 0;
}