#include<iostream>
#include<string.h>
using namespace std;

int main() {
    char number[19];
    cin >> number;

    int length = strlen(number);

    while (length--)
        cout << number[length];

    return 0;
}